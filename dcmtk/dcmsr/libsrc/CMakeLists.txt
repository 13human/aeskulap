# create library from source files
ADD_LIBRARY(dcmsr dsrcitem dsrcodtn dsrcodvl dsrcomtn dsrcomvl dsrcontn dsrcsidl dsrdattn dsrdoc dsrdoctn dsrdoctr dsrdtitn dsrimgfr dsrimgtn dsrimgvl dsrnumtn dsrnumvl dsrpnmtn dsrreftn dsrscogr dsrscotn dsrscovl dsrsoprf dsrstrvl dsrtcodt dsrtcosp dsrtcotn dsrtcoto dsrtcovl dsrtextn dsrtimtn dsrtncsr dsrtree dsrtypes dsruidtn dsrwavch dsrwavtn dsrwavvl dsrxmlc dsrxmld dsriodcc dsrbascc dsrenhcc dsrcomcc dsrkeycc dsrmamcc dsrchecc dsrprocc dsrxrdcc)

# declare installation files
INSTALL_TARGETS(${INSTALL_LIBDIR} dcmsr)
