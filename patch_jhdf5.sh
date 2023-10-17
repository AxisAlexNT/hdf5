#!/bin/bash
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
cd "${SCRIPT_DIR}"
git clone https://sissource.ethz.ch/sispub/jhdf5.git
pwd
ls -alh
rm -fR java/src/jni
cp -af jhdf5/source/c/jni java/src/
cp -af jhdf5/source/c/*.c java/src/jni/
