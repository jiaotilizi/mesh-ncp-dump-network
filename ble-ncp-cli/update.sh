#! /bin/bash

if test -z "${SDK}"
then
    set environment variable SDK
    exit 1
fi

find uart -type f -exec diff ${SDK}/app/bluetooth/examples_ncp_host/common/'{}' '{}' ';'

find protocol -type f -exec cp ${SDK}/'{}' '{}' ';'

find protocol -type f -exec diff ${SDK}/'{}' '{}' ';'
