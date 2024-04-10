SUMMARY = "Xilinx Bootgen Tool"
HOMEPAGE = "https://github.com/Xilinx/bootgen"
DESCRIPTION = "Tool for generating bootable images for Xilinx devices"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://LICENSE;md5=c979df673927004a489691fc457facff"

SRC_URI = "git://github.com/Xilinx/bootgen.git;protocol=https;tag=2019.2"
SRC_URI[sha256sum] = "48af0970b84f05330a7c453e89fbdb19eecd2ac906eb238c6d3a40b8065c4c19"


S = "${WORKDIR}/git"

# https://github.com/FRRouting/frr/issues/14469
DEBUG_PREFIX_MAP:remove = "-fcanon-prefix-map"

IMAGE_INSTALL += " openssl-dev"
DEPENDS += "openssl"

do_compile() {
    oe_runmake LIBS="/usr/lib/x86_64-linux-gnu/libssl.a /usr/lib/x86_64-linux-gnu/libcrypto.a -ldl -lpthread"
}


do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/bootgen ${D}${bindir}
}