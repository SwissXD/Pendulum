#ifndef Window_hpp_included
#define Window_hpp_included

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>

#include "Pendel.hxx"

class Window 
{
	MathematicalPendulum P1 = MathematicalPendulum(5.12,10.1);
	sf::RenderWindow mWindow;
	sf::RenderStates mStates;

public:
	Window()
		: mWindow{ sf::VideoMode{800,500}, "Pendulum" }
	{
		mWindow.setVerticalSyncEnabled(false);
	}

	int Run()
	{
		typedef std::chrono::steady_clock ClockT;
		ClockT::time_point Tp = ClockT::now();


		for(;;)
		{

			const ClockT::time_point Now = ClockT::now();
			if(std::chrono::duration_cast<std::chrono::duration<double, std::chrono::seconds::period>>(Now - Tp).count() > 0.1)
			{
				Tp = Now;
				P1.Tick();
			}

			mWindow.clear(sf::Color::Black);
			mWindow.draw(P1);
			mWindow.display();
		}
	}
};

#endif // !Window_hpp_included
