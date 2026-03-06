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

      window_.change_extent({ 1280, 720 });
      window_.change_position({ SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED });
      window_.change_title("Magma");
      window_.change_visibility(true);
   }

   bool Magma::tick()
   {
      return true;
   }

   bool Magma::process_event(SDL_Event& event)
   {
      switch (event.type)
      {
         case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
            return false;

         default:
            return true;
      }
   }
}