#include "MovieDatabase.h"

int main() {
    MovieDatabase movie_fake("fakeFileToCauseError.txt");
    MovieDatabase movie_base("data4customers.txt");
    movie_base.readInventoryFile("data4movies.txt");
    movie_base.readCustomerActions("data4commands.txt");
    return 0;
}
