#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
IMAGE="${KH2_PS2_IMAGE:-kh2-local/ps2-compiler:3.2-ee-040921-objdiff}"
MODE="${1:-ensure}"

if ! command -v docker >/dev/null 2>&1; then
  echo "error: docker is required" >&2
  exit 1
fi

if [[ ! -f "${SCRIPT_DIR}/ee-gcc3.2-040921-full.tar.gz" ]]; then
  echo "error: missing ${SCRIPT_DIR}/ee-gcc3.2-040921-full.tar.gz. Have you ran 'git lfs pull'?" >&2
  exit 1
fi

# Sony PS2 SDK libraries (Runtime Library 3.0.0) were built with ee-gcc 2.9-991111.
# Fetch it from decomp.me's compiler releases into tools/compilers/ (not committed).
SDK_CC_DIR="${SCRIPT_DIR}/../../tools/compilers/ee-gcc2.9-991111"
if [[ ! -x "${SDK_CC_DIR}/bin/ee-gcc" ]]; then
  echo "fetching ee-gcc2.9-991111 (Sony SDK compiler) from decompme/compilers releases" >&2
  mkdir -p "${SDK_CC_DIR}"
  curl -sSL "https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.9-991111.tar.xz" \
    | tar xJ -C "${SDK_CC_DIR}"
  chmod +x "${SDK_CC_DIR}"/bin/* || true
fi

case "${MODE}" in
  ensure)
    if docker image inspect "${IMAGE}" >/dev/null 2>&1; then
      IMAGE_PLATFORM="$(docker image inspect "${IMAGE}" --format '{{.Os}}/{{.Architecture}}')"
      if [[ "${IMAGE_PLATFORM}" == "linux/amd64" ]]; then
        exit 0
      fi
    fi
    docker build --platform linux/amd64 -t "${IMAGE}" -f "${SCRIPT_DIR}/Dockerfile" "${SCRIPT_DIR}/../.."
    ;;
  --build|build)
    docker build --platform linux/amd64 -t "${IMAGE}" -f "${SCRIPT_DIR}/Dockerfile" "${SCRIPT_DIR}/../.."
    ;;
  *)
    exit 2
    ;;
esac
