#include "magma.hpp"

namespace eru
{
   auto create_application(std::span<char const* const> const arguments) -> std::unique_ptr<Application>
   {
      return std::make_unique<mgm::Magma>(arguments);
   }
}

namespace mgm
{
   Magma::Magma(std::span<char const* const> const)
      : Application{ "Magma" }
   {
   }
}