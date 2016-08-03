///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Partial.hh
// Copyright   :  (c) Andy Arvanitis 2016
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Partial FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef PartialFFI_HH
#define PartialFFI_HH

#include "PureScript/PureScript.hh"

namespace Partial {

  using namespace PureScript;

  // foreign import crashWith :: forall a. Partial => String -> a
  //
  inline auto crashWith(const any&, const any& msg) -> any {
    throw runtime_error(msg);
  }

}

#endif // PartialFFI_HH
