triangle[k] += std::max(triangle.at(k + n), triangle.at(k + n + 1));
			std::cout << "\nnode: " << triangle.at(k) << "\n";
			