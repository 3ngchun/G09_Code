#include <stdexcept>
#include "RoomItem.h"

char RoomItems::printinfo() {
	return 0;
}
string RoomItems::getItemName() {
	return " ";
}
int RoomItems::getX() {
	return x;
}
void RoomItems::setX(int x) {
	this->x = x;
}
int RoomItems::getY() {
	return y;
}
void RoomItems::setY(int x) {
	this->y = y;
}
char LockedDoor::printinfo() {
	char item = ']';
	return item;
}
string LockedDoor::getItemName() {
	return itemName;
}

int LockedDoor::getX() {
	return x;
}
void LockedDoor::setX(int x) {
	this->x = x;
}
int LockedDoor::getY() {
	return y;
}
void LockedDoor::setY(int x) {
	this->y = y;
}

char UnlockedDoor::printinfo() {
	char item = '[';
	return item;
}
string UnlockedDoor::getItemName() {
	return itemName;
}

int UnlockedDoor::getX() {
	return x;
}
void UnlockedDoor::setX(int x) {
	this->x = x;
}
int UnlockedDoor::getY() {
	return y;
}
void UnlockedDoor::setY(int x) {
	this->y = y;
}

char Chair::printinfo()
{
	char item = 'h';
	return item;
}
string Chair::getItemName() {
	return itemName;
}

int Chair::getX() {
	return x;
}
void Chair::setX(int x) {
	this->x = x;
}
int Chair::getY() {
	return y;
}
void Chair::setY(int x) {
	this->y = y;
}

char Table::printinfo()
{
	char item = 'T';
	return item;
}
string Table::getItemName() {
	return itemName;
}

int Table::getX() {
	return x;
}
void Table::setX(int x) {
	this->x = x;
}
int Table::getY() {
	return y;
}
void Table::setY(int x) {
	this->y = y;
}

char Bed::printinfo()
{
	char item = '=';
	return item;
}
string Bed::getItemName() {
	return itemName;
}

int Bed::getX() {
	return x;
}
void Bed::setX(int x) {
	this->x = x;
}
int Bed::getY() {
	return y;
}
void Bed::setY(int x) {
	this->y = y;
}

char Plant::printinfo()
{
	char item = '+';
	return item;
}
string Plant::getItemName() {
	return itemName;
}

int Plant::getX() {
	return x;
}
void Plant::setX(int x) {
	this->x = x;
}
int Plant::getY() {
	return y;
}
void Plant::setY(int x) {
	this->y = y;
}

char Light::printinfo()
{
	char item = '*';
	return item;
}
string Light::getItemName() {
	return itemName;
}

int Light::getX() {
	return x;
}
void Light::setX(int x) {
	this->x = x;
}
int Light::getY() {
	return y;
}
void Light::setY(int x) {
	this->y = y;
}