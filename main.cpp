#include <SFML/Graphics.hpp>

using namespace sf;

void shapes()
// Прорисовка различных геометрических фигур
{
	/*
	// Устанавливаем 8-ой уровень сглаживания
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	*/
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(1000, 500), "SFML Works!");

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		// window.waitEvent(event);
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// Тогда закрываем его
				window.close();
		}
		// Задаём цвет фона
		window.clear(Color(150, 400, 100, 0));

		// Создаём фигуру: круг радиусом 100
		CircleShape circle(100);
		// Закрашиваем наш круг 
		circle.setFillColor(Color(100, 150, 0));
		// Устанавливаем толщину контура круга
		circle.setOutlineThickness(5);
		// Устанавливаем цвет контура
		circle.setOutlineColor(Color(100, 100, 0));
		// Перемещаем круг для корректного отображения в окне
		circle.move(5, 5);
		// Отрисовка круга
		window.draw(circle);

		// Создаём фигуру: треугольник
		CircleShape triangle(120, 3);
		triangle.setPosition(180, 5); // устанавливаем начальную позицию справа от круга
		// Закрашиваем
		triangle.setFillColor(Color(200, 200, 0));
		// Устанавливаем толщину контура
		triangle.setOutlineThickness(5);
		// Устанавливаем цвет контура
		triangle.setOutlineColor(Color(100, 100, 0));
		window.draw(triangle);

		// Создаём фигуру: квадрат
		CircleShape square(100, 4);
		square.setPosition(375, 5);
		// Закрашиваем
		square.setFillColor(Color(150, 150, 0));
		// Устанавливаем толщину контура
		square.setOutlineThickness(5);
		// Устанавливаем цвет контура
		square.setOutlineColor(Color(100, 100, 0));
		window.draw(square);

		// Создаём фигуру: октагон
		CircleShape octagon(100, 8);
		octagon.setPosition(590, 5);
		// Закрашиваем
		octagon.setFillColor(Color(100, 0, 100));
		// Устанавливаем толщину контура
		octagon.setOutlineThickness(5);
		// Устанавливаем цвет контура
		octagon.setOutlineColor(Color(100, 100, 0));
		window.draw(octagon);

		// Заготовка фигуры многоугольника
		ConvexShape convex;
		// Устанавливаем ему 5 вершин
		convex.setPointCount(5);
		// Устанавливаем координаты вершин
		convex.setPoint(0, Vector2f(0, 210));
		convex.setPoint(1, Vector2f(100, 250));
		convex.setPoint(2, Vector2f(150, 400));
		convex.setPoint(3, Vector2f(50, 500));
		convex.setPoint(4, Vector2f(50, 420));
		// Устанавливаем цвет многоугольника
		convex.setFillColor(Color::Blue);
		// Теперь сдвинем его вниз чуть-чуть вправо
		convex.move(15, 0);
		// Отрисовка многоугольника
		window.draw(convex);

		// Создаём прямоугольник размером 150:250
		RectangleShape rectangle(Vector2f(150.f, 250.f));
		// Перемещаем его в нижний ряд справа от многоугольника
		rectangle.move(200, 220);
		// Устанавливаем ему цвет
		rectangle.setFillColor(Color(150, 100, 150));
		// Отрисовка прямоугольника
		window.draw(rectangle);

		// Линия с заданной толщиной
		RectangleShape line_with_thickness(Vector2f(250.f, 5.f));
		// Поворачиваем её на 45 градусов
		line_with_thickness.rotate(45.f);
		// Устанавливаем цвет
		line_with_thickness.setFillColor(Color::Black);
		// Перемещаем её в нижний ряд справа от прямоугольника
		line_with_thickness.move(400, 220);
		// Отрисовка линии
		window.draw(line_with_thickness);

		// Линия с нулевой толщиной. Создаём её в качестве массива вершин типа Vortex
		Vertex line_without_thickness[] =
		{
			// Координата первой вершины
			Vertex(Vector2f(550.f, 450.f)),
			// Координата второй вершины
			Vertex(Vector2f(750.f, 220.f))
		};
		// Устанавливаем цвет линии - чёрный
		line_without_thickness->color = Color::Black;
		// Отрисовка линии
		window.draw(line_without_thickness, 2, Lines);

		// Отрисовка окна	
		window.display();
	}

}

void one_texture()
// Работа с текстурами
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(1000, 500), "SFML Works!");

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		// window.waitEvent(event);
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// Тогда закрываем его
				window.close();
		}
		// Задаём цвет фона
		window.clear(Color(150, 400, 100, 0));

		// Создаём переменную текстуры
		Texture texture;
		// Подгружаем нашу текстуру из файла
		texture.loadFromFile("C:\\Users\\Anastasiya_Notebook\\Desktop\\Работа\\Программирование\\Проекты VS\\SFML тест\\SFML_test\\Debug\\whale.png");
		// Подгружаем лишь кусок размером 100х100 из файла, начиная с координат 10х10:
		// texture.loadFromFile("C:\\Users\\Anastasiya_Notebook\\Desktop\\Работа\\Программирование\\Проекты VS\\SFML тест\\SFML_test\\Debug\\whale.png", IntRect(10, 10, 100, 100));
		// Включаем режим сглаживания для нашей текстуры
		// texture.setSmooth(true);
		// Создаём спрайт и устанавливаем ему нашу текстуру
		// Sprite sprite(texture);
		// Включаем режим повторения для текстуры
		texture.setRepeated(true);
		// Создаём спрайт размером 400х400 и присваиваем ему нашу текстуру (текстура имеет размер 100х100)
		Sprite sprite(texture, IntRect(0, 0, 400, 400));
		// Отрисовка спрайта	 
		window.draw(sprite);

		// Отрисовка окна	
		window.display();
	}

}

void different_colors_texture()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(1000, 500), "SFML Works!");

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		// window.waitEvent(event);
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// Тогда закрываем его
				window.close();
		}
		// Задаём цвет фона
		window.clear(Color(150, 400, 100, 0));

		// Создаём переменную текстуры
		Texture texture;
		// Подгружаем лишь кусок размером 100х100 из файла, начиная с координат 10х10:
		texture.loadFromFile("C:\\Users\\Anastasiya_Notebook\\Desktop\\Работа\\Программирование\\Проекты VS\\SFML тест\\SFML_test\\Debug\\whale.png", IntRect(10, 10, 100, 100));
		
		// Создаём семь спрайтов для примера
		Sprite sprite1(texture);
		Sprite sprite2(texture);
		Sprite sprite3(texture);
		Sprite sprite4(texture);
		Sprite sprite5(texture);
		Sprite sprite6(texture);
		Sprite sprite7(texture);
		// Первый спрайт остаётся на месте в качестве образца
		// Сдвигаем второй спрайт вправо на 105 пикселей
		sprite2.move(105, 0);
		// Устанавливаем ему цвет - зелёный
		sprite2.setColor(Color::Green);
		// Сдвигаем третий спрайт вправо на 210 пикселей
		sprite3.move(210, 0);
		// Устанавливаем ему цвет - красный
		sprite3.setColor(Color::Red);
		// Сдвигаем четвёртый спрайт вправо на 315 пикселей
		sprite4.move(315, 0);
		// Устанавливаем ему цвет - жёлтый
		sprite4.setColor(Color::Yellow);
		// Сдвигаем пятый спрайт вправо на 420 пикселей
		sprite5.move(420, 0);
		// Устанавливаем ему цвет – белый + прозрачность 128
		sprite5.setColor(Color(255, 255, 255, 128));
		// Сдвигаем шестой спрайт вправо на 525 пикселей
		sprite6.move(525, 0);
		// Устанавливаем ему цвет – белый + прозрачность 64
		sprite6.setColor(Color(255, 255, 255, 64));
		// Сдвигаем седьмой спрайт вправо на 630 пикселей
		sprite7.move(630, 0);
		// Устанавливаем ему цвет – белый + прозрачность 32
		sprite7.setColor(Color(255, 255, 255, 32));
		// Отрисовка всех спрайтов	
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);
		window.draw(sprite6);
		window.draw(sprite7);

		// Отрисовка окна	
		window.display();
	}
}

void texture_transformation()
/* К спрайтам могут быть применены различные варианты трансформаций:
			изменение позиции, изменение ориентации в пространстве и масштабирование.
			Все они выполняются с помощью методов
			setPosition/move, setRotation/rotate и setScale/scale */
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(1000, 500), "SFML Works!");

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		// window.waitEvent(event);
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// Тогда закрываем его
				window.close();
		}
		// Задаём цвет фона
		window.clear(Color(150, 400, 100, 0));

		// Создаём переменную текстуры
		Texture texture;
		// Подгружаем лишь кусок размером 100х100 из файла, начиная с координат 10х10:
		texture.loadFromFile("C:\\Users\\Anastasiya_Notebook\\Desktop\\Работа\\Программирование\\Проекты VS\\SFML тест\\SFML_test\\Debug\\whale.png", IntRect(10, 10, 100, 100));
		
		// Создаём пять спрайтов для примера
		Sprite sprite1(texture);
		Sprite sprite2(texture);
		// Включаем режим сглаживания для нашей текстуры
		// texture.setSmooth(true);
		Sprite sprite3(texture);
		Sprite sprite4(texture);
		Sprite sprite5(texture);

		// Позиция
		sprite1.setPosition(10.f, 30.f); // абсолютное значение
		sprite2.move(170.f, 10.f); // смещение относительно текущей позиции

		// Вращение
		sprite3.setPosition(450.f, 30.f); // сначала сдвинем наш спрайт в сторону
		sprite3.setScale(3.0f, 4.5f); // абсолютное значение масштаба
		sprite3.setRotation(45.f); // абсолютное значение в 45°
		// sprite.rotate(15.f); // можно задать смещение относительно текущего значения угла (+15°)

		// Масштаб
		sprite4.setPosition(10, 150); // сначала сдвинем наш спрайт вниз
		sprite4.setScale(0.3f, 0.9f); // абсолютное значение масштаба

		sprite5.setPosition(100, 170); // сначала сдвинем наш спрайт в сторону
		sprite5.scale(1.5f, 0.2); // смещение параметров масштабирования относительно текущих значений

		// Отрисовка всех спрайтов
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);

		// Отрисовка окна	
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