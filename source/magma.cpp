#include "magma.hpp"

namespace eru
{
   std::unique_ptr<Application> create_application(std::span<char const* const> const arguments)
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

   bool Magma::tick()
   {
      return true;
   }
}