#!/usr/bin/env bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

cd ${SCRIPT_DIR}

echo $'\n' >> mx_code_gen.log

DATE=$(date)
echo "STM32CubeMX code generated ${DATE}" >> mx_code_gen.log

cd ../Core/Src/
if find main.c 2>/dev/null; then
rm main.c 2>/dev/null
echo "deleted auto-generated main.c from ${SCRIPT_DIR}" >> "${SCRIPT_DIR}/mx_code_gen.log"
fi

