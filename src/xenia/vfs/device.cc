/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "xenia/vfs/device.h"

namespace xe {
namespace vfs {

Device::Device(const std::string& mount_path) : mount_path_(mount_path) {}

Device::~Device() = default;

}  // namespace vfs
}  // namespace xe
