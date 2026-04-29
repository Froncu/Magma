#ifndef MAGMA_HPP
#define MAGMA_HPP

#include "eruptor/eruptor.hpp"

namespace mgm
{
   class Magma final : public eru::Application
   {
      public:
         explicit Magma(eru::PassKey<eru::Locator> construction_key);
         Magma(Magma const&) = delete;
         Magma(Magma&&) noexcept = delete;

         ~Magma() override = default;

         auto operator=(Magma const&) -> Magma& = delete;
         auto operator=(Magma&&) noexcept -> Magma& = delete;

         [[nodiscard]] auto tick() -> bool override;

      private:
         eru::Platform const& platform_{ eru::Locator::get<eru::Platform>() };
         eru::Renderer const& renderer_{ eru::Locator::get<eru::Renderer>() };
   };
}

#endif