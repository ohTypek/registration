#include <iostream>
#include <fstream>

int calculate_age() {
  int birthdate;

  std::cout << "Enter your year of birth: ";
  std::cin >> birthdate;

  return 2023 - birthdate;
}

bool IsLoggedIN() {

  std::string username, password, un, pw;

  std::cout << "Twoja nazwa: ";
  std::cin >> username;

  std::cout << "Twoje haslo: ";
  std::cin >> password;

  std::ifstream read("registration-files/" + username + ".txt");
  getline(read, un);
  getline(read, pw);

  if(un == username && pw == password) {
    return true;
  } else {
    return false;
  }
}

int age_check() {

  int age = calculate_age();

  if(age < 12) {
    if (age < 0) {
      std::cout << "Error!\n";
      age_check();
    }
    std::cout << "Jesteś za młody.\n";
    system("PAUSE");
    return false;

  } else if(age > 12 && age < 18) {
    std::cout << "Potrzebujesz rodzica do zalogowania.\n";
    system("PAUSE");

  } else {
    std::cout << "Odpowiedni wiek. Kontynuuj.\n";
  }

  return true;
}

int main() {
  int choice;

  std::cout << "1: Rejestruj\n2: Loguj\nTwoj wybor: ";
  std::cin >> choice;

  if(choice == 1 && age_check()) {
    std::string username, password;

    std::cout << "wybierz nazwe: ";
    std::cin >> username;
    std::cout << "wybierz haslo: ";
    std::cin >> password;

    std::ofstream file;
    file.open("registration-files/" + username + ".txt");
    file << username << std::endl << password;
    file.close();

    main();

  } else if(choice == 2) {
    bool status = IsLoggedIN();

  if(!status) {
    std::cout << "Zly login!\n";
    system("PAUSE");
    return 0;

  } else {
    std::cout << "Pomyślnie zalogowano!\n";
    system("PAUSE");
    return 1;
  }

  }
}

