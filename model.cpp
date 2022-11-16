#include "chocan.h"

model::model()
{

}

model::model(const model & copy):
    first_name(copy.first_name), last_name(copy.last_name)
    ,address(copy.address), city(copy.city)
    ,state(copy.state),email(copy.email)
    ,zipcode(0000)
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