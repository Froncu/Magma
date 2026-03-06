#ifndef MAGMA_HPP
#define MAGMA_HPP

#include "eruptor/eruptor.hpp"

namespace mgm
{
   class Magma final : public eru::Application
   {
      public:
         explicit Magma(std::span<char const* const> arguments);
         Magma(Magma const&) = delete;
         Magma(Magma&&) noexcept = delete;

         virtual ~Magma() override = default;

         Magma& operator=(Magma const&) = delete;
         Magma& operator=(Magma&&) noexcept = delete;

         [[nodiscard]] virtual bool tick() override;

      private:
         eru::Window& window_{ eru::Locator::get<eru::Window>() };
   };
}

#endif