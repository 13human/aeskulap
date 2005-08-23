/*
 *
 *  Copyright (C) 1997-2001, OFFIS
 *
 *  This software and supporting documentation were developed by
 *
 *    Kuratorium OFFIS e.V.
 *    Healthcare Information and Communication Systems
 *    Escherweg 2
 *    D-26121 Oldenburg, Germany
 *
 *  THIS SOFTWARE IS MADE AVAILABLE,  AS IS,  AND OFFIS MAKES NO  WARRANTY
 *  REGARDING  THE  SOFTWARE,  ITS  PERFORMANCE,  ITS  MERCHANTABILITY  OR
 *  FITNESS FOR ANY PARTICULAR USE, FREEDOM FROM ANY COMPUTER DISEASES  OR
 *  ITS CONFORMITY TO ANY SPECIFICATION. THE ENTIRE RISK AS TO QUALITY AND
 *  PERFORMANCE OF THE SOFTWARE IS WITH THE USER.
 *
 *  Module:  dcmjpeg
 *
 *  Author:  Marco Eichelberg, Norbert Olges
 *
 *  Purpose: Codec class for decoding JPEG Baseline (lossy, 8-bit)
 *
 *  Last Update:      $Author: braindead $
 *  Update Date:      $Date: 2005/08/23 19:31:53 $
 *  Source File:      $Source: /cvsroot/aeskulap/aeskulap/dcmtk/dcmjpeg/libsrc/djdecbas.cc,v $
 *  CVS/RCS Revision: $Revision: 1.1 $
 *  Status:           $State: Exp $
 *
 *  CVS/RCS Log at end of file
 *
 */

#include "osconfig.h"
#include "djdecbas.h"
#include "djcparam.h"
#include "djrploss.h"

#include "djdijg8.h"


DJDecoderBaseline::DJDecoderBaseline()
: DJCodecDecoder()
{
}


DJDecoderBaseline::~DJDecoderBaseline()
{
}


E_TransferSyntax DJDecoderBaseline::supportedTransferSyntax() const
{
  return EXS_JPEGProcess1TransferSyntax;
}


DJDecoder *DJDecoderBaseline::createDecoderInstance(
    const DcmRepresentationParameter * /* toRepParam */,
    const DJCodecParameter *cp,
    Uint8 /* bitsPerSample */,
    OFBool isYBR) const
{
  return new DJDecompressIJG8Bit(*cp, isYBR);
}


/*
 * CVS/RCS Log
 * $Log: djdecbas.cc,v $
 * Revision 1.1  2005/08/23 19:31:53  braindead
 * - initial savannah import
 *
 * Revision 1.1  2005/06/26 19:26:14  pipelka
 * - added dcmtk
 *
 * Revision 1.1  2001/11/13 15:58:25  meichel
 * Initial release of module dcmjpeg
 *
 *
 */
