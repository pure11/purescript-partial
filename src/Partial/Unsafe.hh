///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Console.hh
// Copyright   :  (c) Andy Arvanitis 2016
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Console FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef PartialUnsafeFFI_HH
#define PartialUnsafeFFI_HH

#include "PureScript/PureScript.hh"

namespace Partial_Unsafe {

  using namespace PureScript;

  // foreign import unsafePartial :: forall a. (Partial => a) -> a
  //
  inline auto unsafePartial(const any& f) -> any {
    return f(undefined);
  }

  // foreign import unsafePartialBecause :: forall a. String -> (Partial => a) -> a
  //
  inline auto unsafePartialBecause(const string& reason, const any& f) -> any {
    try {
      return unsafePartial(f);
    } catch (std::runtime_error&) {
      throw runtime_error("unsafePartial failed. The following "
                          "assumption was incorrect: '" + reason + "'.");
    }
  }

}

#endif // PartialUnsafeFFI_HH
