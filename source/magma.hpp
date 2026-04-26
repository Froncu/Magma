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

         ~Magma() override = default;

         auto operator=(Magma const&) -> Magma& = delete;
         auto operator=(Magma&&) noexcept -> Magma& = delete;
   };
}

#endif