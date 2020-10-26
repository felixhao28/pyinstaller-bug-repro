#include <string>
#include <vector>
#include <iostream>
#include <boost/process.hpp>
#include <boost/filesystem.hpp>
namespace bp = ::boost::process;

int main() {
    std::vector<std::string> args;
    auto is = new bp::ipstream();
    auto os = new bp::opstream();
    auto c = new bp::child("tk", bp::args(args), bp::std_in < *os, bp::std_out > * is, bp::std_err > stderr);
    std::string line;
    getline(*is, line);
    std::cout << line << std::endl;
    c->join();
    return 0;
}