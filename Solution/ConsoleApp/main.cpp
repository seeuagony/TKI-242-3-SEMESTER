#include <iostream>
#include "Film.h"
#include "MediaType.h"
#include "Sale.h"
#include "FilmLibrary.h"
#include "film_utils.h"

using namespace std;
using namespace miit::cinema;

/**
 * @brief точка входа в программу
 * @return 0 при успешном выполнении
 */
int main(void) {
    FilmLibrary library;
    library.run_interactive_menu();
    return 0;
}