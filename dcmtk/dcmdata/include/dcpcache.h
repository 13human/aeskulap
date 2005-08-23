/*
 *
 *  Copyright (C) 1994-2002, OFFIS
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
 *  Module:  dcmdata
 *
 *  Author:  Marco Eichelberg
 *
 *  Purpose: class DcmPrivateTagCache
 *
 *  Last Update:      $Author: braindead $
 *  Update Date:      $Date: 2005/08/23 19:32:00 $
 *  Source File:      $Source: /cvsroot/aeskulap/aeskulap/dcmtk/dcmdata/include/Attic/dcpcache.h,v $
 *  CVS/RCS Revision: $Revision: 1.1 $
 *  Status:           $State: Exp $
 *
 *  CVS/RCS Log at end of file
 *
 */

#ifndef DCPCACHE_H
#define DCPCACHE_H

#include "osconfig.h"    /* make sure OS specific configuration is included first */
#include "oftypes.h"     /* for OFBool */
#include "oflist.h"      /* for OFList */
#include "ofstring.h"    /* for OFString */
#include "dctagkey.h"    /* for DcmTagKey */

class DcmObject;

/** class handling one entry of the Private Tag Cache List
 */
class DcmPrivateTagCacheEntry
{
public:
  /** constructor
   *  @param tk tag key for private creator element
   *  @param pc private creator name, must not be NULL or empty string
   */
  DcmPrivateTagCacheEntry(const DcmTagKey& tk, const char *pc);

  /// destructor
  virtual ~DcmPrivateTagCacheEntry();

  /** returns the private creator name
   */
  const char *getPrivateCreator() const;

  /** checks if this element is the private creator for the element
   *  with the given tag key
   *  @param tk tag key to check
   *  @return OFTrue if this element contains the matching private creator,
   *    OFFalse otherwise.
   */
  OFBool isPrivateCreatorFor(const DcmTagKey& tk) const;

private:

  /// private undefined copy constructor
  DcmPrivateTagCacheEntry(const DcmPrivateTagCacheEntry&);
  
  /// private undefined copy assignment operator
  DcmPrivateTagCacheEntry& operator=(const DcmPrivateTagCacheEntry&);

  /// the tag key of the private creator element
  DcmTagKey tagKey;

  /// the private creator name
  OFString privateCreator;
};


/** this class implements a cache of Private Creator elements
 *  and corresponding reserved tag numbers.
 */
class DcmPrivateTagCache: private OFList<DcmPrivateTagCacheEntry *>
{
public:
  /// default constructor
  DcmPrivateTagCache();

  /// destructor
  virtual ~DcmPrivateTagCache();

  /// resets the cache to default-constructed state
  void clear();

  /** looks up the private creator name for the given private tag
   *  @param tk private tag to check
   *  @return private creator name if found, NULL otherwise.
   */
  const char *findPrivateCreator(const DcmTagKey& tk) const;

  /** updates the private creator cache with the given object.
   *  If the object points to a private creator element,
   *  the tag key and creator code are added to the cache.
   *  Otherwise, the cache remains unmodified.
   */
  void updateCache(DcmObject *dobj);

private:

  /// private undefined copy constructor
  DcmPrivateTagCache(const DcmPrivateTagCache&);
  
  /// private undefined copy assignment operator
  DcmPrivateTagCache& operator=(const DcmPrivateTagCache&);

};

#endif

/*
 * CVS/RCS Log:
 * $Log: dcpcache.h,v $
 * Revision 1.1  2005/08/23 19:32:00  braindead
 * - initial savannah import
 *
 * Revision 1.1  2005/06/26 19:25:53  pipelka
 * - added dcmtk
 *
 * Revision 1.1  2002/07/23 14:21:27  meichel
 * Added support for private tag data dictionaries to dcmdata
 *
 *
 */
