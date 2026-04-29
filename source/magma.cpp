#include "magma.hpp"

namespace eru
{
   auto provide_application(std::span<char const* const> const) -> void
   {
      Locator::provide<Application, mgm::Magma>();
   }
}

namespace mgm
{
   Magma::Magma(eru::PassKey<eru::Locator> const construction_key)
      : Application{ construction_key }
   {
   }

   auto Magma::tick() -> bool
   {
      platform_.poll();
      return true;
   }
}