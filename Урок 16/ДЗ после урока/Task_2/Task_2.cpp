#include <iostream>
#include <vector>
#include <stdexcept>

// Определение структуры Видеомагазин
struct VideoStore
{
	std::string filmName;
	std::string director;
	std::string genre;
	int popularityRating;
	double discPrice;
};

// Функция для показа всех записей
void ShowFilms(std::vector<VideoStore> const& films)
{
	for (size_t i = 0; i < films.size(); ++i)
	{
		const VideoStore& film = films[i];
		std::cout << "Название фильма: " << film.filmName
			<< ", Режиссер: " << film.director
			<< ", Жанр: " << film.genre
			<< ", Рейтинг популярности: " << film.popularityRating
			<< ", Цена диска: " << film.discPrice << " руб." << std::endl;
	}
}

// Функция поиска по названию
VideoStore* GetFilmByName(std::vector<VideoStore>& films, const std::string& filmName)
{
	for (VideoStore& film : films)
	{
		if (film.filmName == filmName)
		{
			return &film;
		}
	}
	return nullptr;
}

// Функция поиска по жанру
std::vector<VideoStore> GetFilmsByGenre(std::vector<VideoStore> const& films, std::string const& genre)
{
	std::vector<VideoStore> result;
	for (VideoStore const& film : films)
	{
		if (film.genre == genre)
		{
			result.push_back(film);
		}
	}
	return result;
}

// Функция поиска по режиссеру
std::vector<VideoStore> GetFilmsByDirector(std::vector<VideoStore>& films, std::string& director)
{
	std::vector<VideoStore> result;
	for (const VideoStore& film : films)
	{
		if (film.director == director)
		{
			result.push_back(film);
		}
	}
	return result;
}

// Функция для определения самого популярного фильма в жанре
VideoStore GetMostPopularFilmByGenre(std::vector<VideoStore> const& films, std::string const& genre)
{
	int maxRating = -1;
	VideoStore* mostPopularFilm = nullptr;

	for (const VideoStore& film : films)
	{
		if (film.genre == genre && film.popularityRating > maxRating)
		{
			mostPopularFilm = const_cast<VideoStore*>(&film);
			maxRating = film.popularityRating;
		}
	}

	if (mostPopularFilm != nullptr)
	{
		return *mostPopularFilm;
	}

	throw std::runtime_error("Фильм в данном жанре не найден.");
}

int main()
{
	setlocale(LC_ALL, "rus");

	// Вектор для хранения фильмов
	std::vector<VideoStore> films;

	// Добавление фильмов в вектор
	films.push_back({ "Фильм 1", "Режиссер 1", "Комедия", 5, 299.99 });
	films.push_back({ "Фильм 2", "Режиссер 2", "Боевик", 8, 399.99 });
	films.push_back({ "Фильм 3", "Режиссер 1", "Комедия", 7, 349.99 });
	films.push_back({ "Фильм 4", "Режиссер 3", "Боевик", 9, 449.99 });

	// Показ всех записей
	std::cout << "Все фильмы в магазине: " << std::endl;
	ShowFilms(films);

	// Поиск по названию
	std::string filmName = "Фильм 2";
	VideoStore* filmByName = GetFilmByName(films, filmName);
	if (filmByName)
	{
		std::cout << "Найден фильм по названию `" << filmName << "`: " << std::endl;
		std::cout << filmByName->filmName << ", Режиссер: " << filmByName->director << std::endl;
	}
	else
	{
		std::cout << "Фильм с названием `" << filmName << "` не найден." << std::endl;
	}
	std::cout << std::endl;

	// Поиск по жанру
	std::string genre = "Комедия";
	std::vector<VideoStore> filmsByGenre = GetFilmsByGenre(films, genre);

	std::cout << "Фильмы жанра `" << genre << "`:" << std::endl;
	ShowFilms(filmsByGenre);

	// Поиск по режиссеру
	std::string director = "Режиссер 1";
	std::vector<VideoStore> filmsByDirector = GetFilmsByDirector(films, director);
	std::cout << "Фильмы режиссера `" << director << "`:" << std::endl;
	ShowFilms(filmsByDirector);

	// Самый популярный фильм в жанре
	try
	{
		std::string genre = "Комедия";
		VideoStore mostPopular = GetMostPopularFilmByGenre(films, genre);
		std::cout << "Самый популярный фильм в жанре `" << genre << "`:" << std::endl;
		std::cout << mostPopular.filmName << ", Рейтинг популярности: " << mostPopular.popularityRating << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}