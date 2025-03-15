{
  pkgs ? import <nixpkgs> {},
}:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
    wireshark
    nmap
    john
    qemu
  ];
}
