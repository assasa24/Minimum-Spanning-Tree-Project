#include "Utility.h"

/*********************************************************************/
inline bool digitOrSpace(char c) {

	return (c == ' ' || (c >= '0' && c <= '9'));
}

/*********************************************************************/
/* This Function checks that the string contains only legal characters
 */
bool checkIfValidChar(string& line, bool checkWithMinus) {

	for (int i = 0; i < line.size(); i++) {

		if (!(digitOrSpace(line[i]) || (checkWithMinus && line[i] == '-'))) {

			char temp = line[i];
			line = "invalid character inserted: '";
			line += temp;
			line += "'";
			line += " is an invalid input. \n";

			return false;
		}
	}

	return true;
}

/*********************************************************************/
bool checkFileOpened(ifstream& input, ofstream& output, string& line) {

	if (input.fail() || output.fail())
	{
		line = "Error occured while trying to open the files";
		return false;
	}
	return true;
}

/*********************************************************************/
 /* This Function checks that the current line is not an empty line.
 * And sets line as the line that was inserted.
 */
bool checkEmptyLine(ifstream& input, string& line) {

	if (!getline(input, line))
	{
		line = "empty line. invalid input \n";
		return false;
	}

	return true;
}

/*********************************************************************/
 /* This Function checks that the current line is legal according to the expected input,
 * And assigns the value to num_of_vertices.
 */
bool checkLegalLine_NumOfVertices(string& line, int& num_of_vertices) {

	num_of_vertices = 0;

	if (!checkIfValidChar(line, DoNotCheckWithMinus)) {

		return false;
	}

	num_of_vertices = std::stoi(line);
	if (num_of_vertices <= 0) {

		line = "number of vertices in a graph can't be a non-positive number. invalid input\n";
		return false;
	}

	return true;
}

/*********************************************************************/
/* This Function checks that the current line is legal according to the expected input,
 * And assigns the value to num_of_edges.
 */
bool checkLegalLine_NumOfEdges(string& line, int& num_of_edges) {

	num_of_edges = 0;

	if (!checkIfValidChar(line, DoNotCheckWithMinus)) {

		return false;
	}

	num_of_edges = std::stoi(line);
	if (num_of_edges < 0) {

		line = "number of edges in a graph can't be a negative number. invalid input\n";
		return false;
	}

	return true;
}

/*********************************************************************/
/* This Function checks that the current line is legal according to the expected input,
 * And assigns the value to ver1, ver2 & ver3.
 *
 * Expected format of a line: "{int} {int} {int}"
 * ASSUMPTION: there are no duplicate edges {v1,v2} & {v1,v2} or {v2,v1}
 */
bool checkLegalLine_WeightedEdge(string& line, int num_of_vertices, int& ver1, int& ver2, int& weight) {

	ver1 = ver2 = weight = 0;

	if (!checkIfValidChar(line, CheckWithMinus)) {

		return false;
	}

	int check = sscanf(line.c_str(), "%d %d %d", &ver1, &ver2, &weight);

	if (check != 3) {

		line = "wrong input format. invalid input \n";

		return false;
	}

	if (!(ver1 >= 1 && ver1 <= num_of_vertices && ver2 >= 1 && ver2 <= num_of_vertices && ver1 != ver2)) {

		line = "invalid edge. invalid input \n";

		return false;
	}

	return true;
}

/*********************************************************************/
/* This Function checks that the current line is legal according to the expected input,
 * And assigns the value to ver1 and ver2.
 *
 * Expected format of a line: "{int} {int}"
 */
bool checkLegalLine_RemovedEdge(string& line, Graph* g, int& ver1, int& ver2) {

	ver1 = ver2 = 0;

	if (!checkIfValidChar(line, DoNotCheckWithMinus)) {

		return false;
	}

	int dump;

	int check = sscanf(line.c_str(), "%d %d %d", &ver1, &ver2, &dump);

	if (check != 2) {

		line = "wrong input format. invalid input \n";

		return false;
	}

	if (!(ver1 >= 1 && ver1 <= g->get_Num_of_Vertices() && ver2 >= 1 && ver2 <= g->get_Num_of_Vertices() && ver1 != ver2)) {

		line = "invalid edge. invalid input \n";

		return false;
	}

	// if edge inserted wasn't in the graph:

	if (!(g->IsAdjacent(ver1, ver2))) {

		line = "Edge (";
		line += ver1;
		line += ", ";
		line += ver2;
		line += ") wasn't in graph. invalid input \n";

		return false;
	}

	return true;
}

/*********************************************************************/
void deleteEverything(ifstream& input, ofstream& output, Graph*& g1, Graph*& g2, Graph*& g3)
{
	if (input.is_open())
		input.close();
	if (output.is_open())
		output.close();
	if (!g1)
		delete g1;
	if (!g2)
		delete g2;
	if (!g3)
		delete g3;
}

/*********************************************************************/
