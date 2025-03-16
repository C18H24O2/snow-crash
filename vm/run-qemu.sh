#!/usr/bin/env bash

set -euo pipefail

ISO="snow-crash.iso"

if [ ! -f "$ISO" ]; then
	ISO="vm/snow-crash.iso"
	if [ ! -f "$ISO" ]; then
		echo "Downloading $ISO"
		curl -L -o "$ISO" https://cdn.intra.42.fr/isos/SnowCrash.iso
	fi
fi

echo "Running VM"
qemu-system-x86_64 \
    -m 2G \
    -cdrom "$ISO" \
    -enable-kvm \
    -cpu host \
    -smp 4
