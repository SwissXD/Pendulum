
#ifndef Pendel_hpp_included
#define Pendel_hpp_included

#include "Util.hxx"
#include <math.h>
#include <SFML/Graphics.hpp>



class MathematicalPendulum : public sf::Drawable
{
private:
	double m_length;
	double m_start_alpha;
	double m_alpha;
	double xc,yc; // Aufhängug des Pendels
	double xP,yP; // Position des Pendels
public:
	virtual void draw(sf::RenderTarget& Target, sf::RenderStates States) const override
	{
		sf::CircleShape Center;
		Center.setRadius(5);
		Center.setFillColor(sf::Color::White);
		Center.setOrigin(Center.getRadius(),Center.getRadius());
		Center.setPosition(xc, yc);
		Target.draw(Center);

		
		sf::Vertex line[] =
		{
	    sf::Vertex(sf::Vector2f(xc, yc)),
	    sf::Vertex(sf::Vector2f(xP, yP))
		};

		Target.draw(line, 2, sf::Lines);

		sf::CircleShape M;
		M.setRadius(15);
		M.setFillColor(sf::Color::Blue);
		M.setOrigin(M.getRadius(),M.getRadius());
		M.setPosition(xP, yP);
		Target.draw(M);
	}
	MathematicalPendulum(double length, double alpha): m_length(length),m_start_alpha(alpha), m_alpha(alpha), xc(400), yc(100)
	{
		this->xP = std::cos(Pendel::deg2rad(m_start_alpha)) * m_length;
		this->yP = std::sin(Pendel::deg2rad(m_start_alpha)) * m_length;
	}
	double getPeriodicTimeInMS()
	{
		return (2*Pendel::pi*std::sqrt(m_length/Pendel::gERDE*10));
	}
	void Tick()
	{
		double step = m_start_alpha/this->getPeriodicTimeInMS()/10;
		std::cout << xP << '\n';
		if (m_alpha > -this->m_start_alpha)
		{
			m_alpha -= step;
		}

		this->xP = std::cos(Pendel::deg2rad(m_alpha)) * m_length * 30;
		this->yP = std::sin(Pendel::deg2rad(m_alpha)) * m_length * 30;
	}

};


#endif