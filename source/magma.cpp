#include "magma.hpp"

namespace eru
{
   Application* create_application(std::span<char const* const> const arguments)
   {
      return new mgm::Magma{ arguments };
   }
}

namespace mgm
{
   Magma::Magma(std::span<char const* const> const arguments)
   {
      for (auto&& argument : arguments)
         eru::Locator::get<eru::Logger>().info(argument);
   }

   bool Magma::tick()
   {
      return false;
   }

   bool Magma::process_event(SDL_Event& event)
   {
      switch (event.type)
      {
         default:
            return true;
      }
   }
}