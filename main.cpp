#include <SFML/Graphics.hpp>

using namespace sf;

void shapes()
// ���������� ��������� �������������� �����
{
	/*
	// ������������� 8-�� ������� �����������
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	*/
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(1000, 500), "SFML Works!");

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		// window.waitEvent(event);
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		// ����� ���� ����
		window.clear(Color(150, 400, 100, 0));

		// ������ ������: ���� �������� 100
		CircleShape circle(100);
		// ����������� ��� ���� 
		circle.setFillColor(Color(100, 150, 0));
		// ������������� ������� ������� �����
		circle.setOutlineThickness(5);
		// ������������� ���� �������
		circle.setOutlineColor(Color(100, 100, 0));
		// ���������� ���� ��� ����������� ����������� � ����
		circle.move(5, 5);
		// ��������� �����
		window.draw(circle);

		// ������ ������: �����������
		CircleShape triangle(120, 3);
		triangle.setPosition(180, 5); // ������������� ��������� ������� ������ �� �����
		// �����������
		triangle.setFillColor(Color(200, 200, 0));
		// ������������� ������� �������
		triangle.setOutlineThickness(5);
		// ������������� ���� �������
		triangle.setOutlineColor(Color(100, 100, 0));
		window.draw(triangle);

		// ������ ������: �������
		CircleShape square(100, 4);
		square.setPosition(375, 5);
		// �����������
		square.setFillColor(Color(150, 150, 0));
		// ������������� ������� �������
		square.setOutlineThickness(5);
		// ������������� ���� �������
		square.setOutlineColor(Color(100, 100, 0));
		window.draw(square);

		// ������ ������: �������
		CircleShape octagon(100, 8);
		octagon.setPosition(590, 5);
		// �����������
		octagon.setFillColor(Color(100, 0, 100));
		// ������������� ������� �������
		octagon.setOutlineThickness(5);
		// ������������� ���� �������
		octagon.setOutlineColor(Color(100, 100, 0));
		window.draw(octagon);

		// ��������� ������ ��������������
		ConvexShape convex;
		// ������������� ��� 5 ������
		convex.setPointCount(5);
		// ������������� ���������� ������
		convex.setPoint(0, Vector2f(0, 210));
		convex.setPoint(1, Vector2f(100, 250));
		convex.setPoint(2, Vector2f(150, 400));
		convex.setPoint(3, Vector2f(50, 500));
		convex.setPoint(4, Vector2f(50, 420));
		// ������������� ���� ��������������
		convex.setFillColor(Color::Blue);
		// ������ ������� ��� ���� ����-���� ������
		convex.move(15, 0);
		// ��������� ��������������
		window.draw(convex);

		// ������ ������������� �������� 150:250
		RectangleShape rectangle(Vector2f(150.f, 250.f));
		// ���������� ��� � ������ ��� ������ �� ��������������
		rectangle.move(200, 220);
		// ������������� ��� ����
		rectangle.setFillColor(Color(150, 100, 150));
		// ��������� ��������������
		window.draw(rectangle);

		// ����� � �������� ��������
		RectangleShape line_with_thickness(Vector2f(250.f, 5.f));
		// ������������ � �� 45 ��������
		line_with_thickness.rotate(45.f);
		// ������������� ����
		line_with_thickness.setFillColor(Color::Black);
		// ���������� � � ������ ��� ������ �� ��������������
		line_with_thickness.move(400, 220);
		// ��������� �����
		window.draw(line_with_thickness);

		// ����� � ������� ��������. ������ � � �������� ������� ������ ���� Vortex
		Vertex line_without_thickness[] =
		{
			// ���������� ������ �������
			Vertex(Vector2f(550.f, 450.f)),
			// ���������� ������ �������
			Vertex(Vector2f(750.f, 220.f))
		};
		// ������������� ���� ����� - ������
		line_without_thickness->color = Color::Black;
		// ��������� �����
		window.draw(line_without_thickness, 2, Lines);

		// ��������� ����	
		window.display();
	}

}

void one_texture()
// ������ � ����������
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(1000, 500), "SFML Works!");

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		// window.waitEvent(event);
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		// ����� ���� ����
		window.clear(Color(150, 400, 100, 0));

		// ������ ���������� ��������
		Texture texture;
		// ���������� ���� �������� �� �����
		texture.loadFromFile("C:\\Users\\Anastasiya_Notebook\\Desktop\\������\\����������������\\������� VS\\SFML ����\\SFML_test\\Debug\\whale.png");
		// ���������� ���� ����� �������� 100�100 �� �����, ������� � ��������� 10�10:
		// texture.loadFromFile("C:\\Users\\Anastasiya_Notebook\\Desktop\\������\\����������������\\������� VS\\SFML ����\\SFML_test\\Debug\\whale.png", IntRect(10, 10, 100, 100));
		// �������� ����� ����������� ��� ����� ��������
		// texture.setSmooth(true);
		// ������ ������ � ������������� ��� ���� ��������
		// Sprite sprite(texture);
		// �������� ����� ���������� ��� ��������
		texture.setRepeated(true);
		// ������ ������ �������� 400�400 � ����������� ��� ���� �������� (�������� ����� ������ 100�100)
		Sprite sprite(texture, IntRect(0, 0, 400, 400));
		// ��������� �������	 
		window.draw(sprite);

		// ��������� ����	
		window.display();
	}

}

void different_colors_texture()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(1000, 500), "SFML Works!");

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		// window.waitEvent(event);
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		// ����� ���� ����
		window.clear(Color(150, 400, 100, 0));

		// ������ ���������� ��������
		Texture texture;
		// ���������� ���� ����� �������� 100�100 �� �����, ������� � ��������� 10�10:
		texture.loadFromFile("C:\\Users\\Anastasiya_Notebook\\Desktop\\������\\����������������\\������� VS\\SFML ����\\SFML_test\\Debug\\whale.png", IntRect(10, 10, 100, 100));
		
		// ������ ���� �������� ��� �������
		Sprite sprite1(texture);
		Sprite sprite2(texture);
		Sprite sprite3(texture);
		Sprite sprite4(texture);
		Sprite sprite5(texture);
		Sprite sprite6(texture);
		Sprite sprite7(texture);
		// ������ ������ ������� �� ����� � �������� �������
		// �������� ������ ������ ������ �� 105 ��������
		sprite2.move(105, 0);
		// ������������� ��� ���� - ������
		sprite2.setColor(Color::Green);
		// �������� ������ ������ ������ �� 210 ��������
		sprite3.move(210, 0);
		// ������������� ��� ���� - �������
		sprite3.setColor(Color::Red);
		// �������� �������� ������ ������ �� 315 ��������
		sprite4.move(315, 0);
		// ������������� ��� ���� - �����
		sprite4.setColor(Color::Yellow);
		// �������� ����� ������ ������ �� 420 ��������
		sprite5.move(420, 0);
		// ������������� ��� ���� � ����� + ������������ 128
		sprite5.setColor(Color(255, 255, 255, 128));
		// �������� ������ ������ ������ �� 525 ��������
		sprite6.move(525, 0);
		// ������������� ��� ���� � ����� + ������������ 64
		sprite6.setColor(Color(255, 255, 255, 64));
		// �������� ������� ������ ������ �� 630 ��������
		sprite7.move(630, 0);
		// ������������� ��� ���� � ����� + ������������ 32
		sprite7.setColor(Color(255, 255, 255, 32));
		// ��������� ���� ��������	
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);
		window.draw(sprite6);
		window.draw(sprite7);

		// ��������� ����	
		window.display();
	}
}

void texture_transformation()
/* � �������� ����� ���� ��������� ��������� �������� �������������:
			��������� �������, ��������� ���������� � ������������ � ���������������.
			��� ��� ����������� � ������� �������
			setPosition/move, setRotation/rotate � setScale/scale */
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(1000, 500), "SFML Works!");

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		// window.waitEvent(event);
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		// ����� ���� ����
		window.clear(Color(150, 400, 100, 0));

		// ������ ���������� ��������
		Texture texture;
		// ���������� ���� ����� �������� 100�100 �� �����, ������� � ��������� 10�10:
		texture.loadFromFile("C:\\Users\\Anastasiya_Notebook\\Desktop\\������\\����������������\\������� VS\\SFML ����\\SFML_test\\Debug\\whale.png", IntRect(10, 10, 100, 100));
		
		// ������ ���� �������� ��� �������
		Sprite sprite1(texture);
		Sprite sprite2(texture);
		// �������� ����� ����������� ��� ����� ��������
		// texture.setSmooth(true);
		Sprite sprite3(texture);
		Sprite sprite4(texture);
		Sprite sprite5(texture);

		// �������
		sprite1.setPosition(10.f, 30.f); // ���������� ��������
		sprite2.move(170.f, 10.f); // �������� ������������ ������� �������

		// ��������
		sprite3.setPosition(450.f, 30.f); // ������� ������� ��� ������ � �������
		sprite3.setScale(3.0f, 4.5f); // ���������� �������� ��������
		sprite3.setRotation(45.f); // ���������� �������� � 45�
		// sprite.rotate(15.f); // ����� ������ �������� ������������ �������� �������� ���� (+15�)

		// �������
		sprite4.setPosition(10, 150); // ������� ������� ��� ������ ����
		sprite4.setScale(0.3f, 0.9f); // ���������� �������� ��������

		sprite5.setPosition(100, 170); // ������� ������� ��� ������ � �������
		sprite5.scale(1.5f, 0.2); // �������� ���������� ��������������� ������������ ������� ��������

		// ��������� ���� ��������
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);

		// ��������� ����	
		window.display();
	}
}

int main()
{
	// shapes();
	// one_texture();
	// different_colors_texture();
	texture_transformation();

	return 0;
}