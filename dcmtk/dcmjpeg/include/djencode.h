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
 *  Author:  Marco Eichelberg
 *
 *  Purpose: singleton class that registers encoders for all supported JPEG processes.
 *
 *  Last Update:      $Author: braindead $
 *  Update Date:      $Date: 2005/08/23 19:32:02 $
 *  Source File:      $Source: /cvsroot/aeskulap/aeskulap/dcmtk/dcmjpeg/include/Attic/djencode.h,v $
 *  CVS/RCS Revision: $Revision: 1.1 $
 *  Status:           $State: Exp $
 *
 *  CVS/RCS Log at end of file
 *
 */

#ifndef DJENCODE_H
#define DJENCODE_H

#include "osconfig.h"
#include "oftypes.h"  /* for OFBool */
#include "djutils.h"
#include "dctypes.h"  /* for Uint32 */

class DJCodecParameter;
class DJEncoderBaseline;
class DJEncoderExtended;
class DJEncoderLossless;
class DJEncoderP14SV1;
class DJEncoderProgressive;
class DJEncoderSpectralSelection;

/** singleton class that registers encoders for all supported JPEG processes.
 */
class DJEncoderRegistration 
{
public: 

  /** registers encoders for all supported JPEG processes.
   *  If already registered, call is ignored unless cleanup() has
   *  been performed before.
   *  @param pCompressionCSConversion color conversion mode for compression
   *  @param pCreateSOPInstanceUID mode for SOP Instance UID creation
   *  @param pVerbose verbose mode flag
   *  @param pOptimizeHuffman perform huffman table optimization for 8 bits/pixel compression?
   *  @param pSmoothingFactor smoothing factor for image compression, 0..100
   *  @param pForcedBitDepth forced bit depth for image compression, 0 (auto) or 8/12/16
   *  @param pFragmentSize maximum fragment size (in kbytes) for compression, 0 for unlimited.
   *  @param pCreateOffsetTable create offset table during image compression?
   *  @param pSampleFactors subsampling mode for color image compression
   *  @param pWriteYBR422 flag indicating whether a compressed YBR color stream should 
   *    be marked as YBR_FULL or YBR_FULL_422 on DICOM level
   *  @param pConvertToSC flag indicating whether image should be converted to 
   *    Secondary Capture upon compression
   *  @param pWindowType mode for VOI transformation of monochrome images
   *  @param pWindowParameter parameter for VOI transform of monochrome images, used in modes 1, 2, 4, 6
   *  @param pVoiCenter VOI window center for mode 5
   *  @param pVoiWidth  VOI window width for mode 5
   *  @param pRoiLeft   Region of Interest left corner for for VOI transform of monochrome images, mode 7
   *  @param pRoiTop    Region of Interest upper corner for for VOI transform of monochrome images, mode 7
   *  @param pRoiWidth  Region of Interest width for for VOI transform of monochrome images, mode 7
   *  @param pRoiHeight Region of Interest height for for VOI transform of monochrome images, mode 7
   *  @param pUsePixelValues Check smallest and largest pixel value and optimize compression, mode 0 only
   *  @param pUseModalityRescale Create Rescale Slope/Intercept to scale back 
   *     to original pixel range, mode 0 only
   */
  static void registerCodecs(
    E_CompressionColorSpaceConversion pCompressionCSConversion = ECC_lossyYCbCr,
    E_UIDCreation pCreateSOPInstanceUID = EUC_default,
    OFBool pVerbose = OFFalse,
    OFBool pOptimizeHuffman = OFFalse,
    int pSmoothingFactor = 0,
    int pForcedBitDepth = 0,
    Uint32 pFragmentSize = 0,
    OFBool pCreateOffsetTable = OFTrue,
    E_SubSampling pSampleFactors = ESS_444,
    OFBool pWriteYBR422 = OFFalse,
    OFBool pConvertToSC = OFFalse,
    unsigned long pWindowType = 0,
    unsigned long pWindowParameter = 0,
    double pVoiCenter = 0.0,
    double pVoiWidth = 0.0,
    unsigned long pRoiLeft = 0,
    unsigned long pRoiTop = 0,
    unsigned long pRoiWidth = 0,
    unsigned long pRoiHeight = 0,
    OFBool pUsePixelValues = OFTrue,
    OFBool pUseModalityRescale = OFFalse);

  /** deregisters encoders.
   *  Attention: Must not be called while other threads might still use
   *  the registered codecs, e.g. because they are currently encoding
   *  DICOM data sets through dcmdata.
   */  
  static void cleanup();

private:

  /// flag indicating whether the encoders are already registered.
  static OFBool registered;

  /// pointer to codec parameter shared by all encoders
  static DJCodecParameter *cp;
  
  /// pointer to encoder for baseline JPEG
  static DJEncoderBaseline *encbas;

  /// pointer to encoder for extended JPEG
  static DJEncoderExtended *encext;

  /// pointer to encoder for spectral selection JPEG
  static DJEncoderSpectralSelection *encsps;

  /// pointer to encoder for progressive JPEG
  static DJEncoderProgressive *encpro;

  /// pointer to encoder for lossless SV1 JPEG
  static DJEncoderP14SV1 *encsv1;

  /// pointer to encoder for lossless JPEG
  static DJEncoderLossless *enclol;
  
};

#endif

/*
 * CVS/RCS Log
 * $Log: djencode.h,v $
 * Revision 1.1  2005/08/23 19:32:02  braindead
 * - initial savannah import
 *
 * Revision 1.1  2005/06/26 19:26:09  pipelka
 * - added dcmtk
 *
 * Revision 1.2  2001/11/19 15:13:29  meichel
 * Introduced verbose mode in module dcmjpeg. If enabled, warning
 *   messages from the IJG library are printed on ofConsole, otherwise
 *   the library remains quiet.
 *
 * Revision 1.1  2001/11/13 15:56:27  meichel
 * Initial release of module dcmjpeg
 *
 *
 */
