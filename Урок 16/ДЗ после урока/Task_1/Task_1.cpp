#include <iostream>
#include <vector>
#include <algorithm>

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
	for (auto const& film : films)
	{
		std::cout << "Название фильма: " << film.filmName
			<< ", Режиссер: " << film.director
			<< ", Жанр: " << film.genre
			<< ", Рейтинг популярности: " << film.popularityRating
			<< ", Цена диска: " << film.discPrice << " руб." << std::endl;
	}
	std::cout << std::endl;
}

// Функция поиска по названию
VideoStore* GetFilmByName(std::vector<VideoStore>& films, std::string const& filmName)
{
	auto it = std::find_if(films.begin(), films.end(), [&filmName](const VideoStore& film) 
		{
			return film.filmName == filmName;
		}
	);

	if (it != films.end()) 
	{
		return &(*it);
	}

	return nullptr;
}

// Функция поиска по жанру
std::vector<VideoStore> GetFilmsByGenre(std::vector<VideoStore> const& films, std::string const& genre)
{
	std::vector<VideoStore> result;

	std::copy_if(films.begin(), films.end(), std::back_inserter(result), [&genre](VideoStore const& film)
		{
			return film.genre== genre;
		}
	);

	return result;
}

// Функция поиска по режиссеру
std::vector<VideoStore> GetFilmsByDirector(std::vector<VideoStore> const& films, std::string const& director)
{
	std::vector<VideoStore> result;

	std::copy_if(films.begin(), films.end(), std::back_inserter(result), [&director](VideoStore const& film)
		{
			return film.director == director;
		}
	);

	return result;
}

// Функция для определения самого популярного фильма в жанре
VideoStore GetMostPopularFilmByGenre(std::vector<VideoStore> const& films, std::string const& genre)
{
	auto result = std::max_element(films.begin(), films.end(), [&genre](VideoStore const& a, VideoStore const& b)
		{
			return a.genre == genre && b.genre == genre ? a.popularityRating < b.popularityRating : false;
		}
	);

	if (result != films.end() && result->genre == genre) 
	{
		return *result;
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

