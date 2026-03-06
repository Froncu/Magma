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
   {
      window_.change_extent({ 1280, 720 });
      window_.change_visibility(true);
   }

   bool Magma::tick()
   {
      return true;
   }
}