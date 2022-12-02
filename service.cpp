#include "chocan.h"
#include <time.h>
#include <cctype>
#define NAME_SZ 20
#define COMMENT_SZ 100

service_directory available_services;

void service_list::add_new_service_record()
{
	service temp;
	temp.create();

	vector<service>::iterator t = list.begin();
	while ( ((*t).compare_dates(temp)) <= 0 )
		t++;

	list.insert(t, temp);
	cout << "\n\tService record saved.\n" << endl;
}

void service_list::display_all_services()
{
	for (unsigned int i = 0; i < list.size(); i++)
		list[i].display();
}

float service_list::total_cost()
{
	float sum = 0.0;
	for (unsigned int i = 0; i < list.size(); i++)
		sum += list[i].get_cost();
	
	return sum;
}

int service_list::num_services() { return list.size(); }



service::service(): date_of_service("Date of service not saved"),
	code(0), name("No service name saved"), comments("No comments"),
	cost(0.0), current_date("Date of record not saved")
{
	name.reserve(NAME_SZ);
	comments.reserve(COMMENT_SZ);
}

void service::create()
{
	cout << "\n\t\t[ADDING A NEW SERVICE RECORD]" << endl;

	enter_date();
	get_service_dir_data();

	// enter comments (optional)
	char resp;
	cout << "\n\tWould you like to add any additional comments? (Y/N):  ";
	do {
		cin >> resp;
		
		if ('Y' != resp && 'y' != resp && 'N' != resp && 'n' != resp) {
			cout << "\n\tDid not understand your response. Please enter 'Y' or 'N'.\n"
				<< "Would you like to add any additional comments?  ";
		}
		else break;
	} while (true);
	if ('Y' == resp || 'y' == resp) {
		cout << "\n\tPlease enter them here: (500 character limit)\n";
		getline(cin, comments, '\n');
	}

	get_curr_date();

	cout << "\n\tService record created.\n" << endl;
}

void service::display() const
{
	cout << "\n\t" << name << " (" << code << ") - $" << cost;
	cout << "\n\tDate provided: " << date_of_service;
	cout << "\n\tDate recorded: " << current_date;
	cout << "\n\t" << comments << endl;
}

int service::compare_dates(service &to_cmp)
{
	// compare years
	string y = date_of_service.substr(6, 4);
	string cmp_y = to_cmp.date_of_service.substr(6, 4);
	if (parse_date(y) < parse_date(cmp_y))	return -1;
	if (parse_date(y) > parse_date(cmp_y))	return 1;

	// years are the same, compare months
	string m = date_of_service.substr(0, 2);
	string cmp_m = to_cmp.date_of_service.substr(0, 2);
	if (parse_date(m) < parse_date(cmp_m))	return -1;
	if (parse_date(m) > parse_date(cmp_m))	return 1;

	// months also the same, compare days
	string d = date_of_service.substr(3, 2);
	string cmp_d = to_cmp.date_of_service.substr(3, 2);
	if (parse_date(d) < parse_date(cmp_d))	return -1;
	if (parse_date(d) > parse_date(cmp_d))	return 1;

	return 0;
}

void service::read_from_disk()
{
	ifstream ifile("provider.txt");

}

float service::get_cost() { return cost; }


void service::enter_date()
{
	string m, d, y;
	char valid = 0;
	cout << "\n\tDate of service (MM-DD-YYYY):  ";
	do {
		getline(cin, m, '-');
		getline(cin, d, '-');
		getline(cin, y, '\n');

		valid = check_date(m, d, y);
		if (!valid) {
			cout << "\n\tInvalid date. Please check your entry and try again.\n" << endl;
			cout << "\tRe-enter Date of service (MM-DD-YYYY): ";
		}
	} while (!valid);

	date_of_service = m + "-" + d + "-" + y;
}

void service::get_service_dir_data()
{
	cout << "\n\tName of service provided:  ";
	do {
		getline(cin, name, '\n');
		code = available_services.find_code_by_name(prep_str(name));
		
		if (code < 0) {
			cout << "\n\tInvalid service name. Please check your entry and try again.\n" << endl;
			cout << "\tRe-enter name of service provided:  ";
		}
	} while (code < 0);
	cost = available_services.find_cost_by_name(name);
	capitalize_name();
}

void service::get_curr_date()
{
	char conv_t[26];
	time_t t = time(NULL);
	ctime_r(&t, conv_t);
	
	// get date
	switch(conv_t[4]+conv_t[5]+conv_t[6]) {
		case 'J' + 'a' + 'n':	current_date = "01-";	break;
		case 'F' + 'e' + 'b':	current_date = "02-";	break;
		case 'M' + 'a' + 'r':	current_date = "03-";	break;
		case 'A' + 'p' + 'r':	current_date = "04-";	break;
		case 'M' + 'a' + 'y':	current_date = "05-";	break;
		case 'J' + 'u' + 'n':	current_date = "06-";	break;
		case 'J' + 'u' + 'l':	current_date = "07-";	break;
		case 'A' + 'u' + 'g':	current_date = "08-";	break;
		case 'S' + 'e' + 'p':	current_date = "09-";	break;
		case 'O' + 'c' + 't':	current_date = "10-";	break;
		case 'N' + 'o' + 'v':	current_date = "11-";	break;
		case 'D' + 'e' + 'c':	current_date = "12-";	break;
	}
	current_date = (current_date + conv_t[8] + conv_t[9] + "-");
	current_date = (current_date + conv_t[20] + conv_t[21] + conv_t[22] + conv_t[23] + " ");

	// get time
	for (int i = 11; i < 19; i++)
		current_date += conv_t[i];
}

int service::parse_date(string date)
{
	int sum = 0;
	for (unsigned int i = 0; i < date.size(); i++) {
		int pos = 1;
		for (int j = (date.size() - (i+1)); j > 0; j--) {
			pos *= 10;
		}
		sum += (date[i] * pos);
	}
	return sum;
}

bool service::check_date(string m, string d, string y)
{
	int month = parse_date(m), day = parse_date(d), year = parse_date(y);

	if (month < '1' || month > ('1'*10)+'2' || day < '1')
		return false;

	switch(month) {
		case '1':
		case '3':
		case '5':
		case '7':
		case '8':
		case ('1'*10)+'0':
		case ('1'*10)+'2':
			if (day > ('3'*10)+'1')
				return false;
			break;
		case '4':
		case '6':
		case '9':
		case ('1'*10)+'1':
			if (day > ('3'*10)+'0')
				return false;
			break;
		case '2':
			if (day > ('2'*10)+'8')
				return false;
			break;
		default:
			return false;
	}

	if (year < parse_date("1970") || year > parse_date("2023"))
		return false;

	return true;
}

string service::prep_str(string to_prep)
{
	unsigned int i = 0;
	char temp[to_prep.size() + 1];
	for ( ; i < to_prep.size(); i++)
		temp[i] = tolower(to_prep[i]);
	temp[i] = '\0';
	return string(temp);
}

void service::capitalize_name()
{
	name[0] = toupper(name[0]);
	for (unsigned int i = 1; i < name.size(); i++) {
		if (name[i-1] == ' ')
			name[i] = toupper(name[i]);
		else name[i] = tolower(name[i]);
	}

}



service_directory::service_directory()
{
	// attempt to access database to load services
	ifstream ifile("databases/available_services.txt", ios_base::in);
	if (!ifile) {
		cerr << "\n\nCould not connect to services database.\n\n";
		ifile.close();
		return;
	}

	entry temp;

	// load services for quicker access from app
	do {
		// check if connected
		if (ifile) {
			ifile >> temp.code;	// test read

			// if test read passed, read rest of service info
			if (!ifile.eof() && ifile.is_open()) {
				ifile.ignore();

				getline(ifile, temp.name, '~');

				ifile >> temp.cost;
				ifile.ignore(100, '\n');

				// add newly-read service
				dir.push_back(temp);
			}
		}
	} while (!ifile.eof());
	ifile.close();
}

int service_directory::find_code_by_name(string name)
{
	int low = 0, high = (dir.size() - 1);
	for ( ; low <= high; ) {
		int mid = (low + high) / 2;

		if (name == dir[mid].name)
			return dir[mid].code;

		if (name > dir[mid].name)
			low = mid + 1;
		else high = mid - 1;
	}

	return -1;
}

float service_directory::find_cost_by_name(string name)
{
	int low = 0, high = (dir.size() - 1);
	for ( ; low <= high ; ) {
		int mid = (low + high) / 2;

		if (name == dir[mid].name)
			return dir[mid].cost;

		if (name > dir[mid].name)
			low = mid + 1;
		else high = mid - 1;
	}

	return -1.0;
}

void service_directory::display_all()
{
	for (unsigned int i = 0; i < dir.size(); i++) {
		cout << "\n\t" << dir[i].name
			<< "\t(" << dir[i].code
			<< ")\t$" << dir[i].cost << endl;
	}
}

bool service_directory::is_code_valid(int to_check)
{
	for (unsigned int i = 0; i < dir.size(); i++) {
		if (dir[i].code == to_check)
			return true;
	}

	return false;
}