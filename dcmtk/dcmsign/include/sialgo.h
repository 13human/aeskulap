/*
 *
 *  Copyright (C) 1998-2003, OFFIS
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
 *  Module: dcmsign
 *
 *  Author: Norbert Loxen, Marco Eichelberg
 *
 *  Purpose:
 *    classes: SiAlgorithm
 *
 *  Last Update:      $Author: braindead $
 *  Update Date:      $Date: 2005/08/23 19:32:07 $
 *  CVS/RCS Revision: $Revision: 1.1 $
 *  Status:           $State: Exp $
 *
 *  CVS/RCS Log at end of file
 *
 */

#ifndef SIALGO_H
#define SIALGO_H

#include "osconfig.h"
#include "sitypes.h"

#ifdef WITH_OPENSSL

#include "oftypes.h"

/** 
 *  pure virtual base class of the public key crypto systems used for
 *  signature creation and verification.
 *  All public key algorithm classes should inherit from this class.
 *  Instances of derived classes contain a single private or public key.
 */
class SiAlgorithm
{    
public:

  /// default constructor
  SiAlgorithm() { }
  
  /// destructor
  virtual ~SiAlgorithm() { }

  /** creates a signature.
   *  @param inputHash array of hash key bytes that are to be signed
   *  @param inputHashSize length of hash key array in bytes
   *  @param inputHashAlgorithm MAC algorithm used for creation of hash key.
   *    Required for creation of PKCS#1 RSA signature padding.
   *  @param outputSignature pointer to array of at least getSize() which must be allocated by caller.
   *  @param outputSignatureSize returns the number of bytes written to outputSignature.
   *  @return SI_EC_Normal if successful, errorcode otherwise.
   */
  virtual OFCondition sign(
    const unsigned char *inputHash, 
    unsigned long inputHashSize,
    E_MACType inputHashAlgorithm,
    unsigned char *outputSignature,
    unsigned long &outputSignatureSize) = 0;

  /** verifies a signature.
   *  @param inputHash array of bytes containing hash key to be verified against signature
   *  @param inputHashSize length of hash key array in bytes
   *  @param inputHashAlgorithm MAC algorithm used for creation of hash key.
   *    Required for creation of PKCS#1 RSA signature padding.
   *  @param inputSignature array of bytes containing signature to be verified
   *  @param inputSignatureSize length of signature array in bytes
   *  @param verified returns whether the signature was successfully verified
   *  @return SI_EC_Normal if successful, errorcode otherwise.
   */
  virtual OFCondition verify(
    const unsigned char *inputHash, 
    unsigned long inputHashSize,
    E_MACType inputHashAlgorithm,
    const unsigned char *inputSignature,
    unsigned long inputSignatureSize,
    OFBool &verified) = 0;

  /** returns the size of a block of encrypted/decrypted ciphertext in bytes.
   *  The result depends on the public key algorithm, key size and padding scheme.
   *  In general the input to decrypt() or encrypt() must be less than or equal
   *  to this block size.  The output of decrypt() or encrypt() is always equal
   *  to this block size.
   *  @return block size for this public key cryptosystem and key
   */
  virtual unsigned long getSize() const = 0;

  /** returns the type of public key algorithm computed by this object
   *  @return type of public key algorithm
   */
  virtual E_KeyType keyType() const = 0;    

};

#endif
#endif

/*
 *  $Log: sialgo.h,v $
 *  Revision 1.1  2005/08/23 19:32:07  braindead
 *  - initial savannah import
 *
 *  Revision 1.1  2005/06/26 19:26:15  pipelka
 *  - added dcmtk
 *
 *  Revision 1.4  2003/06/04 14:21:03  meichel
 *  Simplified include structure to avoid preprocessor limitation
 *    (max 32 #if levels) on MSVC5 with STL.
 *
 *  Revision 1.3  2001/09/26 14:30:19  meichel
 *  Adapted dcmsign to class OFCondition
 *
 *  Revision 1.2  2001/06/01 15:50:47  meichel
 *  Updated copyright header
 *
 *  Revision 1.1  2000/11/07 16:48:52  meichel
 *  Initial release of dcmsign module for DICOM Digital Signatures
 *
 *
 */

