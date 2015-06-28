/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_VFS_DEVICES_DISC_IMAGE_DEVICE_H_
#define XENIA_VFS_DEVICES_DISC_IMAGE_DEVICE_H_

#include <memory>
#include <string>

#include "xenia/base/mapped_memory.h"
#include "xenia/vfs/device.h"

namespace xe {
namespace vfs {

class GDFX;

class DiscImageDevice : public Device {
 public:
  DiscImageDevice(const std::string& mount_path,
                  const std::wstring& local_path);
  ~DiscImageDevice() override;

  bool Initialize();

  std::unique_ptr<Entry> ResolvePath(const char* path) override;

  uint32_t total_allocation_units() const override {
    return uint32_t(mmap_->size() / sectors_per_allocation_unit() /
                    bytes_per_sector());
  }
  uint32_t available_allocation_units() const override { return 0; }
  uint32_t sectors_per_allocation_unit() const override { return 1; }
  uint32_t bytes_per_sector() const override { return 2 * 1024; }

 private:
  std::wstring local_path_;
  std::unique_ptr<MappedMemory> mmap_;
  GDFX* gdfx_;
};

}  // namespace vfs
}  // namespace xe

#endif  // XENIA_VFS_DEVICES_DISC_IMAGE_DEVICE_H_
