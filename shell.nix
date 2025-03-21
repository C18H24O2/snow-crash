{
  pkgs ? import <nixpkgs> {},
}:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
    wireshark
    nmap
    john # john password made this
    qemu
  ];
}
