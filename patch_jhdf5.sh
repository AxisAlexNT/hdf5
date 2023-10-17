#!/bin/bash
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
cd "${SCRIPT_DIR}"
git clone https://sissource.ethz.ch/sispub/jhdf5.git
cp -arf jhdf5/source/c/jni hdf5/java/src/
cp -arf jhdf5/source/c/*.c hdf5/java/src/jni/
