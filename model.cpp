#include "chocan.h"

model::model():first_name("none"), last_name("node"), address("none")
            ,city("none"), state("none"), zipcode(0000), email("none")
{

}

model::model(const model &copy):
    first_name(copy.first_name), last_name(copy.last_name)
    ,address(copy.address), city(copy.city)
    ,state(copy.state),zipcode(copy.zipcode)
    ,email(copy.email)
{}    
model::~model()
{

}
void model::input()
{

}

void model::display() const
{

}

void model::read_file(const string& file_name) const
{

}

void model::update_info()
{

}