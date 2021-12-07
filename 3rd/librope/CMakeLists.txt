cmake_minimum_required(VERSION 3.12...3.22)

project(
	"librope"
	LANGUAGES "C"
	VERSION "1.0.0"
	DESCRIPTION "Rope library for C"
	HOMEPAGE_URL "https://github.com/josephg/librope"
)

add_library("librope" "inc/rope.h" "src/rope.c")
target_include_directories("librope" PUBLIC "inc")
