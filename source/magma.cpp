#include "magma.hpp"

namespace eru
{
   auto create_application(std::span<char const* const> const) -> void
   {
      Locator::provide<Application, mgm::Magma>();
   }
}

namespace mgm
{
   Magma::Magma(eru::Locator::ConstructionKey const construction_key)
      : Application{ construction_key, "Magma" }
   {
   }
}