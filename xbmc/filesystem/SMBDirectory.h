#pragma once
/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "IDirectory.h"
#include "SmbFile.h"
#include "MediaSource.h"

namespace XFILE
{
class CSMBDirectory : public IDirectory
{
public:
  CSMBDirectory(void);
  virtual ~CSMBDirectory(void);
  virtual bool GetDirectory(const CURL& url, CFileItemList &items);
  virtual DIR_CACHE_TYPE GetCacheType(const CURL& url) const { return DIR_CACHE_ONCE; };
  virtual bool Create(const CURL& url);
  virtual bool Exists(const CURL& url);
  virtual bool Remove(const CURL& url);

  int Open(const CURL &url);

  //MountShare will try to mount the smb share and return the path to the mount point (or empty string if failed)
  static std::string MountShare(const std::string &smbPath, const std::string &strType, const std::string &strName,
    const std::string &strUser, const std::string &strPass);

  static void UnMountShare(const std::string &strType, const std::string &strName);
  static std::string GetMountPoint(const std::string &strType, const std::string &strName);

  static bool MountShare(const std::string &strType, CMediaSource &share);

private:
  int OpenDir(const CURL &url, std::string& strAuth);
};
}
