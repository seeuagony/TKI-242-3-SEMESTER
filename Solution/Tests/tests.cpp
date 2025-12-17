#include <gtest/gtest.h>
#include "../lib/Film.h"
#include "../lib/MediaType.h"
#include "../lib/Sale.h"
#include "../lib/FilmLibrary.h"
#include "../lib/film_utils.h"

using namespace miit::cinema;

// ==================== Тесты для класса Film ====================

TEST(FilmTest, DefaultConstructor) {
    Film film;
    EXPECT_EQ(film.get_title(), "");
    EXPECT_EQ(film.get_genre(), "");
    EXPECT_EQ(film.get_year(), 0);
    EXPECT_EQ(film.get_director(), "");
    EXPECT_EQ(film.get_description(), "");
    EXPECT_TRUE(film.get_actors().empty());
    EXPECT_TRUE(film.get_available_media().empty());
}

TEST(FilmTest, ParameterizedConstructor) {
    Film film("Inception", "Sci-Fi", 2010, "Christopher Nolan", "A mind-bending thriller");
    EXPECT_EQ(film.get_title(), "Inception");
    EXPECT_EQ(film.get_genre(), "Sci-Fi");
    EXPECT_EQ(film.get_year(), 2010);
    EXPECT_EQ(film.get_director(), "Christopher Nolan");
    EXPECT_EQ(film.get_description(), "A mind-bending thriller");
}

TEST(FilmTest, CopyConstructor) {
    Film film1("Interstellar", "Sci-Fi", 2014, "Christopher Nolan", "Space exploration");
    film1.add_actor("Matthew McConaughey");
    
    Film film2(film1);
    EXPECT_EQ(film2.get_title(), "Interstellar");
    EXPECT_EQ(film2.get_genre(), "Sci-Fi");
    EXPECT_EQ(film2.get_year(), 2014);
    EXPECT_EQ(film2.get_actors().size(), 1);
}

TEST(FilmTest, AssignmentOperator) {
    Film film1("The Matrix", "Sci-Fi", 1999, "Wachowskis", "Reality simulation");
    Film film2;
    
    film2 = film1;
    EXPECT_EQ(film2.get_title(), "The Matrix");
    EXPECT_EQ(film2.get_director(), "Wachowskis");
}

TEST(FilmTest, AddActor) {
    Film film("Avatar", "Sci-Fi", 2009, "James Cameron", "Pandora adventures");
    film.add_actor("Sam Worthington");
    film.add_actor("Zoe Saldana");
    
    EXPECT_EQ(film.get_actors().size(), 2);
    EXPECT_EQ(film.get_actors()[0], "Sam Worthington");
    EXPECT_EQ(film.get_actors()[1], "Zoe Saldana");
}

TEST(FilmTest, AddMedia) {
    Film film("Titanic", "Drama", 1997, "James Cameron", "Love story on a ship");
    MediaType* dvd = new MediaType(DVD, 15.99, 50, &film);
    
    EXPECT_EQ(film.get_available_media().size(), 1);
    EXPECT_EQ(film.get_available_media()[0]->get_format(), DVD);
    
    delete dvd;
}

// ==================== Тесты для класса MediaType ====================

TEST(MediaTypeTest, DefaultConstructor) {
    MediaType media;
    EXPECT_EQ(media.get_format(), DVD);
    EXPECT_EQ(media.get_price(), 0.0);
    EXPECT_EQ(media.get_stock_quantity(), 0);
    EXPECT_EQ(media.get_film(), nullptr);
}

TEST(MediaTypeTest, ParameterizedConstructor) {
    Film film("Test Film", "Action", 2020, "Test Director", "Test description");
    MediaType media(BLURAY, 29.99, 100, &film);
    
    EXPECT_EQ(media.get_format(), BLURAY);
    EXPECT_EQ(media.get_price(), 29.99);
    EXPECT_EQ(media.get_stock_quantity(), 100);
    EXPECT_EQ(media.get_film(), &film);
}

TEST(MediaTypeTest, GetFormatString) {
    MediaType dvd(DVD, 10.0, 50, nullptr);
    MediaType bluray(BLURAY, 20.0, 30, nullptr);
    MediaType digital(DIGITAL, 5.0, 1000, nullptr);
    MediaType vhs(VHS, 3.0, 10, nullptr);
    
    EXPECT_EQ(dvd.get_format_string(), "DVD");
    EXPECT_EQ(bluray.get_format_string(), "Blu-ray");
    EXPECT_EQ(digital.get_format_string(), "Digital");
    EXPECT_EQ(vhs.get_format_string(), "VHS");
}

TEST(MediaTypeTest, ReduceStock) {
    MediaType media(DVD, 15.0, 100, nullptr);
    
    EXPECT_TRUE(media.reduce_stock(50));
    EXPECT_EQ(media.get_stock_quantity(), 50);
    
    EXPECT_TRUE(media.reduce_stock(50));
    EXPECT_EQ(media.get_stock_quantity(), 0);
    
    EXPECT_FALSE(media.reduce_stock(10));
    EXPECT_EQ(media.get_stock_quantity(), 0);
}

TEST(MediaTypeTest, AddStock) {
    MediaType media(BLURAY, 25.0, 10, nullptr);
    
    media.add_stock(20);
    EXPECT_EQ(media.get_stock_quantity(), 30);
    
    media.add_stock(50);
    EXPECT_EQ(media.get_stock_quantity(), 80);
}

// ==================== Тесты для класса Sale ====================

TEST(SaleTest, DefaultConstructor) {
    Sale sale;
    EXPECT_EQ(sale.get_date(), "");
    EXPECT_EQ(sale.get_film(), nullptr);
    EXPECT_EQ(sale.get_media(), nullptr);
    EXPECT_EQ(sale.get_quantity(), 0);
}

TEST(SaleTest, ParameterizedConstructor) {
    Film film("Test", "Action", 2020, "Director", "Description");
    MediaType media(DVD, 15.99, 100, &film);
    Sale sale("2024-01-15", &film, &media, 5);
    
    EXPECT_EQ(sale.get_date(), "2024-01-15");
    EXPECT_EQ(sale.get_film(), &film);
    EXPECT_EQ(sale.get_media(), &media);
    EXPECT_EQ(sale.get_quantity(), 5);
}

TEST(SaleTest, GetTotalAmount) {
    Film film("Test", "Action", 2020, "Director", "Description");
    MediaType media(DVD, 19.99, 100, &film);
    Sale sale("2024-01-15", &film, &media, 3);
    
    EXPECT_DOUBLE_EQ(sale.get_total_amount(), 59.97);
}

TEST(SaleTest, CopyConstructor) {
    Film film("Test", "Action", 2020, "Director", "Description");
    MediaType media(BLURAY, 29.99, 50, &film);
    Sale sale1("2024-02-20", &film, &media, 2);
    
    Sale sale2(sale1);
    EXPECT_EQ(sale2.get_date(), "2024-02-20");
    EXPECT_EQ(sale2.get_quantity(), 2);
    EXPECT_DOUBLE_EQ(sale2.get_total_amount(), 59.98);
}

// ==================== Тесты для класса FilmLibrary ====================

TEST(FilmLibraryTest, InitialState) {
    FilmLibrary library;
    EXPECT_EQ(library.get_films_count(), 0);
    EXPECT_EQ(library.get_media_types_count(), 0);
    EXPECT_EQ(library.get_sales_count(), 0);
}

TEST(FilmLibraryTest, AddFilm) {
    FilmLibrary library;
    library.add_film("The Godfather", "Crime", 1972, "Francis Ford Coppola", "Mafia family saga");
    
    EXPECT_EQ(library.get_films_count(), 1);
    EXPECT_EQ(library.get_film_by_index(0)->get_title(), "The Godfather");
}

TEST(FilmLibraryTest, AddActorToFilm) {
    FilmLibrary library;
    library.add_film("Pulp Fiction", "Crime", 1994, "Quentin Tarantino", "Intertwined stories");
    library.add_actor_to_film("Pulp Fiction", "John Travolta");
    library.add_actor_to_film("Pulp Fiction", "Samuel L. Jackson");
    
    Film* film = library.get_film_by_index(0);
    EXPECT_EQ(film->get_actors().size(), 2);
}

TEST(FilmLibraryTest, AddMediaType) {
    FilmLibrary library;
    library.add_film("Fight Club", "Drama", 1999, "David Fincher", "Underground fighting");
    library.add_media_type("Fight Club", DVD, 14.99, 75);
    library.add_media_type("Fight Club", BLURAY, 24.99, 50);
    
    EXPECT_EQ(library.get_media_types_count(), 2);
    Film* film = library.get_film_by_index(0);
    EXPECT_EQ(film->get_available_media().size(), 2);
}

TEST(FilmLibraryTest, RegisterSale) {
    FilmLibrary library;
    library.add_film("Shawshank Redemption", "Drama", 1994, "Frank Darabont", "Prison escape");
    library.add_media_type("Shawshank Redemption", DVD, 12.99, 100);
    library.register_sale("2024-01-10", "Shawshank Redemption", DVD, 5);
    
    EXPECT_EQ(library.get_sales_count(), 1);
    
    MediaType* media = library.get_media_by_index(0);
    EXPECT_EQ(media->get_stock_quantity(), 95);
}

TEST(FilmLibraryTest, RegisterSaleInsufficientStock) {
    FilmLibrary library;
    library.add_film("Test Film", "Action", 2020, "Director", "Description");
    library.add_media_type("Test Film", DVD, 15.0, 10);
    library.register_sale("2024-01-15", "Test Film", DVD, 5);
    
    EXPECT_EQ(library.get_sales_count(), 1);
    
    library.register_sale("2024-01-16", "Test Film", DVD, 10);
    EXPECT_EQ(library.get_sales_count(), 1);
}

TEST(FilmLibraryTest, GetFilmByIndex) {
    FilmLibrary library;
    library.add_film("Film1", "Action", 2020, "Director1", "Desc1");
    library.add_film("Film2", "Drama", 2021, "Director2", "Desc2");
    
    Film* film1 = library.get_film_by_index(0);
    Film* film2 = library.get_film_by_index(1);
    
    EXPECT_EQ(film1->get_title(), "Film1");
    EXPECT_EQ(film2->get_title(), "Film2");
    EXPECT_EQ(library.get_film_by_index(10), nullptr);
}

// ==================== Тесты для вспомогательных функций ====================

TEST(UtilsTest, FindFilmByTitle) {
    std::vector<Film*> films;
    films.push_back(new Film("Inception", "Sci-Fi", 2010, "Nolan", "Dreams"));
    films.push_back(new Film("Avatar", "Sci-Fi", 2009, "Cameron", "Pandora"));
    
    testing::internal::CaptureStdout();
    print_film_by_title(films, "Inception");
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Inception") != std::string::npos);
    
    for (auto film : films) delete film;
}

TEST(UtilsTest, FindFilmsByGenre) {
    std::vector<Film*> films;
    films.push_back(new Film("Film1", "Action", 2020, "Dir1", "Desc1"));
    films.push_back(new Film("Film2", "Action", 2021, "Dir2", "Desc2"));
    films.push_back(new Film("Film3", "Drama", 2019, "Dir3", "Desc3"));
    
    testing::internal::CaptureStdout();
    print_films_by_genre(films, "Action");
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Film1") != std::string::npos);
    EXPECT_TRUE(output.find("Film2") != std::string::npos);
    
    for (auto film : films) delete film;
}

// ==================== Главная функция для запуска тестов ====================

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}