//
// This file is a part of UERANSIM open source project.
// Copyright (c) 2021 ALİ GÜNGÖR.
//
// The software and all associated files are licensed under GPL-3.0
// and subject to the terms and conditions defined in LICENSE file.
//

#pragma once

#include <algorithm>
#include <cstdint>
#include <vector>

#include <utils/octet_string.hpp>

namespace nr::ue
{

class SqnManager
{
  private:
    uint64_t m_indBitLen;
    uint64_t m_wrappingDelta;
    uint64_t m_limit;

    std::vector<uint64_t> m_sqnArr;

  public:
    SqnManager(uint64_t indBitLen, uint64_t wrappingDelta, uint64_t limit);

  private:
    [[nodiscard]] uint64_t getSeqFromSqn(uint64_t sqn) const;
    [[nodiscard]] uint64_t getIndFromSqn(uint64_t sqn) const;
    [[nodiscard]] uint64_t getSeqMs() const;

  public:
    [[nodiscard]] uint64_t getSqnUL() const;
    [[nodiscard]] OctetString getSqn() const;
    bool checkSqn(uint64_t sqn);
    bool checkSqn(const OctetString &sqn);
};

} // namespace nr::ue
