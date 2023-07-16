#include "cube.h"

void Cube::show() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 9; j += 3) {
            if ((i == 0) || (i == 5)) {
                std::cout << "      ";
                std::cout << cube[i][j] << " " << cube[i][j + 1] << " " << cube[i][j + 2] << std::endl;
            }
            else if (i == 1) {
                std::cout << cube[i][j] << " " << cube[i][j + 1] << " " << cube[i][j + 2] << "|";
                std::cout << cube[i + 1][j] << " " << cube[i + 1][j + 1] << " " << cube[i + 1][j + 2] << "|";
                std::cout << cube[i + 2][j] << " " << cube[i + 2][j + 1] << " " << cube[i + 2][j + 2] << "|";
                std::cout << cube[i + 3][j] << " " << cube[i + 3][j + 1] << " " << cube[i + 3][j + 2] << std::endl;

                std::cout << cube[i][j + 3] << " " << cube[i][j + 4] << " " << cube[i][j + 5] << "|";
                std::cout << cube[i + 1][j + 3] << " " << cube[i + 1][j + 4] << " " << cube[i + 1][j + 5] << "|";
                std::cout << cube[i + 2][j + 3] << " " << cube[i + 2][j + 4] << " " << cube[i + 2][j + 5] << "|";
                std::cout << cube[i + 3][j + 3] << " " << cube[i + 3][j + 4] << " " << cube[i + 3][j + 5] << std::endl;

                std::cout << cube[i][j + 6] << " " << cube[i][j + 7] << " " << cube[i][j + 8] << "|";
                std::cout << cube[i + 1][j + 6] << " " << cube[i + 1][j + 7] << " " << cube[i + 1][j + 8] << "|";
                std::cout << cube[i + 2][j + 6] << " " << cube[i + 2][j + 7] << " " << cube[i + 2][j + 8] << "|";
                std::cout << cube[i + 3][j + 6] << " " << cube[i + 3][j + 7] << " " << cube[i + 3][j + 8] << std::endl;
                i += 3;
                break;
            }
        }
    }
}

void Cube::save() {
    std::ofstream fout("cube_out.txt");
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 9; j += 3) {
            if ((i == 0) || (i == 5)) {
                fout << "      ";
                fout << cube[i][j] << " " << cube[i][j + 1] << " " << cube[i][j + 2] << std::endl;
            }
            else if (i == 1) {
                fout << cube[i][j] << " " << cube[i][j + 1] << " " << cube[i][j + 2] << "|";
                fout << cube[i + 1][j] << " " << cube[i + 1][j + 1] << " " << cube[i + 1][j + 2] << "|";
                fout << cube[i + 2][j] << " " << cube[i + 2][j + 1] << " " << cube[i + 2][j + 2] << "|";
                fout << cube[i + 3][j] << " " << cube[i + 3][j + 1] << " " << cube[i + 3][j + 2] << std::endl;

                fout << cube[i][j + 3] << " " << cube[i][j + 4] << " " << cube[i][j + 5] << "|";
                fout << cube[i + 1][j + 3] << " " << cube[i + 1][j + 4] << " " << cube[i + 1][j + 5] << "|";
                fout << cube[i + 2][j + 3] << " " << cube[i + 2][j + 4] << " " << cube[i + 2][j + 5] << "|";
                fout << cube[i + 3][j + 3] << " " << cube[i + 3][j + 4] << " " << cube[i + 3][j + 5] << std::endl;

                fout << cube[i][j + 6] << " " << cube[i][j + 7] << " " << cube[i][j + 8] << "|";
                fout << cube[i + 1][j + 6] << " " << cube[i + 1][j + 7] << " " << cube[i + 1][j + 8] << "|";
                fout << cube[i + 2][j + 6] << " " << cube[i + 2][j + 7] << " " << cube[i + 2][j + 8] << "|";
                fout << cube[i + 3][j + 6] << " " << cube[i + 3][j + 7] << " " << cube[i + 3][j + 8] << std::endl;
                i += 3;
                break;
            }
        }
    }

    std::cout << "Cube saved" << std::endl;
    show();
    fout.close();
}

void Cube::read_from_file() {
    std::ifstream fin("cube_out.txt");
    char c;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 9; ++j) {
            if ((i == 0) || (i == 5)) {
                fin >> c; cube[i][j] = c;
            }
            else if (i == 1) {
                fin >> c;   cube[i][j] = c;
                fin >> c;   cube[i][j + 1] = c;
                fin >> c;   cube[i][j + 2] = c;
                fin >> c;
                fin >> c;   cube[i + 1][j] = c;
                fin >> c;   cube[i + 1][j + 1] = c;
                fin >> c;   cube[i + 1][j + 2] = c;
                fin >> c;
                fin >> c;   cube[i + 2][j] = c;
                fin >> c;   cube[i + 2][j + 1] = c;
                fin >> c;   cube[i + 2][j + 2] = c;
                fin >> c;
                fin >> c;   cube[i + 3][j] = c;
                fin >> c;   cube[i + 3][j + 1] = c;
                fin >> c;   cube[i + 3][j + 2] = c;

                fin >> c;   cube[i][j + 3] = c;
                fin >> c;   cube[i][j + 4] = c;
                fin >> c;   cube[i][j + 5] = c;
                fin >> c;
                fin >> c;   cube[i + 1][j + 3] = c;
                fin >> c;   cube[i + 1][j + 4] = c;
                fin >> c;   cube[i + 1][j + 5] = c;
                fin >> c;
                fin >> c;   cube[i + 2][j + 3] = c;
                fin >> c;   cube[i + 2][j + 4] = c;
                fin >> c;   cube[i + 2][j + 5] = c;
                fin >> c;
                fin >> c;   cube[i + 3][j + 3] = c;
                fin >> c;   cube[i + 3][j + 4] = c;
                fin >> c;   cube[i + 3][j + 5] = c;

                fin >> c;   cube[i][j + 6] = c;
                fin >> c;   cube[i][j + 7] = c;
                fin >> c;   cube[i][j + 8] = c;
                fin >> c;
                fin >> c;   cube[i + 1][j + 6] = c;
                fin >> c;   cube[i + 1][j + 7] = c;
                fin >> c;   cube[i + 1][j + 8] = c;
                fin >> c;
                fin >> c;   cube[i + 2][j + 6] = c;
                fin >> c;   cube[i + 2][j + 7] = c;
                fin >> c;   cube[i + 2][j + 8] = c;
                fin >> c;
                fin >> c;   cube[i + 3][j + 6] = c;
                fin >> c;   cube[i + 3][j + 7] = c;
                fin >> c;   cube[i + 3][j + 8] = c;

                i += 3;
                break;
            }
        }
        checker.fair_check(cube);
    }
    show();
    fin.close();
}

Cube::Cube() {
    cube.assign(6, std::vector<char>(9));
    for (int i = 0; i < 6; ++i) {
        std::vector<char> ch;
        ch = {'y', 'r', 'g', 'o', 'b', 'w'};
        for (int j = 0; j < 9; ++j) {
            cube[i][j] = ch[i];
        }
    }
    steps = "";
    turns_counter = 0;
}

void Cube::spin() {
    std::string spin;
    std::cout << "Введите команду вращения (0 - выход из программы): ";
    std::cin >> spin;
    while (true) {
        if (spin == "0") {
            break;
        }
        else if ((spin[0] == 'G') || (spin[0] == 'R') || (spin[0] == 'O') || (spin[0] == 'B') || (spin[0] == 'Y') || (spin[0] == 'W')) {
            if (spin[0] == 'G') {
                if (spin[1] == 'R') {
                    if (spin[2] == 'b') {
                        GRb();
                    }
                    else {
                        GR();
                    }
                }
                else if (spin[1] == 'L') {
                    if (spin[2] == 'b') {
                        GLb();
                    }
                    else {
                        GL();
                    }
                }
                else if (spin[1] == 'U') {
                    if (spin[2] == 'b') {
                        GUb();
                    }
                    else {
                        GU();
                    }
                }
                else if (spin[1] == 'D') {
                    if (spin[2] == 'b') {
                        GDb();
                    }
                    else {
                        GD();
                    }
                }
                else if (spin[1] == 'F') {
                    if (spin[2] == 'b') {
                        GFb();
                    }
                    else {
                        GF();
                    }
                }
                else if (spin[1] == 'B') {
                    if (spin[2] == 'b') {
                        GBb();
                    }
                    else {
                        GB();
                    }
                }
                else {
                    std::cout << "Неверный поворот" << std::endl;
                }
            }
            if (spin[0] == 'R') {
                if (spin[1] == 'R') {
                    if (spin[2] == 'b') {
                        RRb();
                    }
                    else {
                        RR();
                    }
                }
                else if (spin[1] == 'L') {
                    if (spin[2] == 'b') {
                        RLb();
                    }
                    else {
                        RL();
                    }
                }
                else if (spin[1] == 'U') {
                    if (spin[2] == 'b') {
                        RUb();
                    }
                    else {
                        RU();
                    }
                }
                else if (spin[1] == 'D') {
                    if (spin[2] == 'b') {
                        RDb();
                    }
                    else {
                        RD();
                    }
                }
                else if (spin[1] == 'F') {
                    if (spin[2] == 'b') {
                        RFb();
                    }
                    else {
                        RF();
                    }
                }
                else if (spin[1] == 'B') {
                    if (spin[2] == 'b') {
                        RBb();
                    }
                    else {
                        RB();
                    }
                }
                else {
                    std::cout << "Неверный поворот" << std::endl;
                }
            }
            if (spin[0] == 'O') {
                if (spin[1] == 'R') {
                    if (spin[2] == 'b') {
                        ORb();
                    }
                    else {
                        OR();
                    }
                }
                else if (spin[1] == 'L') {
                    if (spin[2] == 'b') {
                        OLb();
                    }
                    else {
                        OL();
                    }
                }
                else if (spin[1] == 'U') {
                    if (spin[2] == 'b') {
                        OUb();
                    }
                    else {
                        OU();
                    }
                }
                else if (spin[1] == 'D') {
                    if (spin[2] == 'b') {
                        ODb();
                    }
                    else {
                        OD();
                    }
                }
                else if (spin[1] == 'F') {
                    if (spin[2] == 'b') {
                        OFb();
                    }
                    else {
                        OF();
                    }
                }
                else if (spin[1] == 'B') {
                    if (spin[2] == 'b') {
                        OBb();
                    }
                    else {
                        OB();
                    }
                }
                else {
                    std::cout << "Неверный поворот" << std::endl;
                }
            }
            if (spin[0] == 'B') {
                if (spin[1] == 'R') {
                    if (spin[2] == 'b') {
                        BRb();
                    }
                    else {
                        BR();
                    }
                }
                else if (spin[1] == 'L') {
                    if (spin[2] == 'b') {
                        BLb();
                    }
                    else {
                        BL();
                    }
                }
                else if (spin[1] == 'U') {
                    if (spin[2] == 'b') {
                        BUb();
                    }
                    else {
                        BU();
                    }
                }
                else if (spin[1] == 'D') {
                    if (spin[2] == 'b') {
                        BDb();
                    }
                    else {
                        BD();
                    }
                }
                else if (spin[1] == 'F') {
                    if (spin[2] == 'b') {
                        BFb();
                    }
                    else {
                        BF();
                    }
                }
                else if (spin[1] == 'B') {
                    if (spin[2] == 'b') {
                        BBb();
                    }
                    else {
                        BB();
                    }
                }
                else {
                    std::cout << "Неверный поворот" << std::endl;
                }
            }
            if (spin[0] == 'Y') {
                if (spin[1] == 'R') {
                    if (spin[2] == 'b') {
                        YRb();
                    }
                    else {
                        YR();
                    }
                }
                else if (spin[1] == 'L') {
                    if (spin[2] == 'b') {
                        YLb();
                    }
                    else {
                        YL();
                    }
                }
                else if (spin[1] == 'U') {
                    if (spin[2] == 'b') {
                        YUb();
                    }
                    else {
                        YU();
                    }
                }
                else if (spin[1] == 'D') {
                    if (spin[2] == 'b') {
                        YDb();
                    }
                    else {
                        YD();
                    }
                }
                else if (spin[1] == 'F') {
                    if (spin[2] == 'b') {
                        YFb();
                    }
                    else {
                        YF();
                    }
                }
                else if (spin[1] == 'B') {
                    if (spin[2] == 'b') {
                        YBb();
                    }
                    else {
                        YB();
                    }
                }
                else {
                    std::cout << "Неверный поворот" << std::endl;
                }
            }
            if (spin[0] == 'W') {
                if (spin[1] == 'R') {
                    if (spin[2] == 'b') {
                        WRb();
                    }
                    else {
                        WR();
                    }
                }
                else if (spin[1] == 'L') {
                    if (spin[2] == 'b') {
                        WLb();
                    }
                    else {
                        WL();
                    }
                }
                else if (spin[1] == 'U') {
                    if (spin[2] == 'b') {
                        WUb();
                    }
                    else {
                        WU();
                    }
                }
                else if (spin[1] == 'D') {
                    if (spin[2] == 'b') {
                        WDb();
                    }
                    else {
                        WD();
                    }
                }
                else if (spin[1] == 'F') {
                    if (spin[2] == 'b') {
                        WFb();
                    }
                    else {
                        WF();
                    }
                }
                else if (spin[1] == 'B') {
                    if (spin[2] == 'b') {
                        WBb();
                    }
                    else {
                        WB();
                    }
                }
                else {
                    std::cout << "Неверный поворот" << std::endl;
                }
            }
        }
        else {
            std::cout << "Неверный цвет" << std::endl;
        }
        std::cout << "Введите команду вращения (0 - выход из программы): ";
        std::cin >> spin;
    }
    show();
}

void Cube::generate() {
    srand(time(NULL));
    int count = rand() % 25 + 15;
    for (int i = 0; i < count; ++i) {
        int now = rand() % 6;
        if (now == 0) {
            GR();
        }
        else if (now == 1) {
            RR();
        }
        else if (now == 2) {
            OR();
        }
        else if (now == 3) {
            BR();
        }
        else if (now == 4) {
            GU();
        }
        else if (now == 5) {
            GD();
        }
    }
    std::cout << "Random Spin" << std::endl;
    show();
}

void Cube::clear(double size, unsigned int *color) {
    this->size = size;
    glParams.CURRENT = -1;

    int i, j, k;
    for (i = 0; i < 6; i++) {
        this->colours[i] = color[i];
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            pieces[i][j][2].setColor(0, color[0]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            pieces[i][j][0].setColor(1, color[1]);
        }
    }

    for (k = 0; k < 3; k++) {
        for (j = 0; j < 3; j++) {
            pieces[j][0][k].setColor(2, color[2]);
        }
    }

    for (k = 0; k < 3; k++) {
        for (j = 0; j < 3; j++) {
            pieces[j][2][k].setColor(3, color[3]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (k = 0; k < 3; k++) {
            pieces[0][k][i].setColor(4, color[4]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (k = 0; k < 3; k++) {
            pieces[2][k][i].setColor(5, color[5]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                pieces[i][j][k].size = (size / 3.0) * 0.95;
            }
        }
    }
    for (int i = 0; i < 6; ++i) {
        std::vector <char> ch;
        ch = { 'y', 'r', 'g', 'o', 'b', 'w' };
        for (int j = 0; j < 9; ++j) {
            cube[i][j] = ch[i];
        }
    }
}

void Cube::draw() {
    const double K = 0.65;
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(((1.0 - K) / 2) * size + K * size / 2, ((1.0 - K) / 2) * size + K * size / 2, ((1.0 - K) / 2) * size + K * size / 2);
    glutSolidCube(size * K);
    glPopMatrix();

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                graphic_arr[i][j][k] = true;
            }
        }
    }

    if (glParams.CURRENT != -1) {
        glPushMatrix();
        int i, j, k;

        if (glParams.CURRENT == 0 || glParams.CURRENT == 1) {
            k = (glParams.CURRENT & 1) * 2;
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    graphic_arr[i][j][k] = false;
                }
            }
            glTranslated(size / 2, size / 2, 0);
            glRotatef(rotation_angle[glParams.CURRENT], 0, 0, 1);
            glTranslated(-size / 2, -size / 2, 0);
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    drawer.draw(pieces[i][j][k], size / 3 * i, size / 3 * j, size / 3 * k);
                }
            }
        }
        else if (glParams.CURRENT == 2 || glParams.CURRENT == 3) {
            j = (glParams.CURRENT & 1) * 2;
            for (i = 0; i < 3; i++) {
                for (k = 0; k < 3; k++) {
                    graphic_arr[i][j][k] = false;
                }
            }

            glTranslated(size / 2, 0, size / 2);
            glRotatef(rotation_angle[glParams.CURRENT], 0, 1, 0);
            glTranslated(-size / 2, 0, -size / 2);
            for (i = 0; i < 3; i++) {
                for (k = 0; k < 3; k++) {
                    drawer.draw(pieces[i][j][k], size / 3 * i, size / 3 * j, size / 3 * k);
                }
            }
        }
        else if (glParams.CURRENT == 4 || glParams.CURRENT == 5) {
            i = (glParams.CURRENT & 1) * 2;
            for (j = 0; j < 3; j++) {
                for (k = 0; k < 3; k++) {
                    graphic_arr[i][j][k] = false;
                }
            }

            glTranslated(0, size / 2, size / 2);
            glRotatef(rotation_angle[glParams.CURRENT], 1, 0, 0);
            glTranslated(0, -size / 2, -size / 2);
            for (j = 0; j < 3; j++) {
                for (k = 0; k < 3; k++) {
                    drawer.draw(pieces[i][j][k], size / 3 * i, size / 3 * j, size / 3 * k);
                }
            }
        }
        glPopMatrix();
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (graphic_arr[i][j][k]) {
                    drawer.draw(pieces[i][j][k], size / 3 * i, size / 3 * j, size / 3 * k);
                }
            }
        }
    }
}

void Cube::display() {
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glTranslatef(0, 0, glParams.AXIS);
    glRotatef(glParams.xRot, 1, 0, 0);
    glRotatef(glParams.yRot, 0, 1, 0);
    glTranslatef(glParams.CUBE_SIZE / -2.0, glParams.CUBE_SIZE / -2.0, glParams.CUBE_SIZE / -2.0);
    draw();
    glPopMatrix();
    glutSwapBuffers();
}

void Cube::rot90(int idx, int sign) {
    int i, j, k;
    if (sign == -1) {
        sign = 3;
    }

    while (sign--) {
        if (idx == 0) {
            k = 0;
            for (i = 0; i < 3; ++i) {
                for (j = 0; j < 3; ++j) {
                    temp[j][2 - i] = pieces[i][j][k];
                }
            }
            for (i = 0; i < 3; ++i) {
                for (j = 0; j < 3; ++j) {
                    temp[i][j].rotZ();
                    pieces[i][j][k] = temp[i][j];
                }
            }
        }

        else if (idx == 1) {
            k = 2;
            for (i = 0; i < 3; ++i) {
                for (j = 0; j < 3; ++j) {
                    temp[j][2 - i] = pieces[i][j][k];
                }
            }
            for (i = 0; i < 3; ++i) {
                for (j = 0; j < 3; ++j) {
                    temp[i][j].rotZ();
                    pieces[i][j][k] = temp[i][j];
                }
            }
        }

        else if (idx == 2) {
            j = 0;
            for (i = 0; i < 3; ++i)
                for (k = 0; k < 3; ++k)
                    temp[k][2 - i] = pieces[i][j][k];
            for (i = 0; i < 3; ++i) {
                for (k = 0; k < 3; ++k) {
                    temp[i][k].rotX();
                    pieces[i][j][k] = temp[i][k];
                }
            }
        }

        else if (idx == 3) {
            j = 2;
            for (i = 0; i < 3; ++i)
                for (k = 0; k < 3; ++k)
                    temp[k][2 - i] = pieces[i][j][k];
            for (i = 0; i < 3; ++i) {
                for (k = 0; k < 3; ++k) {
                    temp[i][k].rotX();
                    pieces[i][j][k] = temp[i][k];
                }
            }
        }

        else if (idx == 4) {
            i = 0;
            for (j = 0; j < 3; ++j) {
                for (k = 0; k < 3; ++k) {
                    temp[k][2 - j] = pieces[i][j][k];
                }
            }
            for (j = 0; j < 3; ++j) {
                for (k = 0; k < 3; ++k) {
                    temp[j][k].rotY();
                    pieces[i][j][k] = temp[j][k];
                }
            }
        }

        else if (idx == 5) {
            i = 2;
            for (j = 0; j < 3; ++j) {
                for (k = 0; k < 3; ++k) {
                    temp[k][2 - j] = pieces[i][j][k];
                }
            }
            for (j = 0; j < 3; ++j) {
                for (k = 0; k < 3; ++k) {
                    temp[j][k].rotY();
                    pieces[i][j][k] = temp[j][k];
                }
            }
        }
    }
}

void Cube::timer(int RorL, int) {
    if (glParams.CURRENT != -1) {
        display();
        Rotate(glParams.CURRENT, glParams.SPEED, RorL);
    }
}

void Cube::Rotate(int idx, int angle, int RorL) {
    if (glParams.CURRENT == -1 || glParams.CURRENT == idx) {
        if (RorL == -1) {
            rotation_angle[idx] -= angle;
        }
        else if (RorL == 1) {
            rotation_angle[idx] += angle;
        }

        if (rotation_angle[idx] % 90 != 0) {
            glParams.CURRENT = idx;
            timer(RorL, 0);
        }
        else {
            if ((rotation_angle[idx] < 0) ^ (glParams.CURRENT == 2 || glParams.CURRENT == 3)) {
                rot90(idx, 1);
            }
            else {
                rot90(idx, -1);
            }
            rotation_angle[idx] = 0;
            glParams.CURRENT = -1;
        }
    }
}



void Cube::rotate_clockwise(int turn) {
    char c;
    c = cube[turn][0];
    cube[turn][0] = cube[turn][6];
    cube[turn][6] = cube[turn][8];
    cube[turn][8] = cube[turn][2];
    cube[turn][2] = c;
    c = cube[turn][1];
    cube[turn][1] = cube[turn][3];
    cube[turn][3] = cube[turn][7];
    cube[turn][7] = cube[turn][5];
    cube[turn][5] = c;
}

void Cube::rotate_counterclockwise(int turn) {
    char c;
    c = cube[turn][0];
    cube[turn][0] = cube[turn][2];
    cube[turn][2] = cube[turn][8];
    cube[turn][8] = cube[turn][6];
    cube[turn][6] = c;
    c = cube[turn][1];
    cube[turn][1] = cube[turn][5];
    cube[turn][5] = cube[turn][7];
    cube[turn][7] = cube[turn][3];
    cube[turn][3] = c;
}

void Cube::GR () {
    rotate_clockwise(3);
    char c1, c2, c3;
    c1 = cube[0][2];
    c2 = cube[0][5];
    c3 = cube[0][8];

    cube[0][2] = cube[2][2];
    cube[0][5] = cube[2][5];
    cube[0][8] = cube[2][8];

    cube[2][2] = cube[5][2];
    cube[2][5] = cube[5][5];
    cube[2][8] = cube[5][8];

    cube[5][2] = cube[4][6];
    cube[5][5] = cube[4][3];
    cube[5][8] = cube[4][0];

    cube[4][0] = c3;
    cube[4][3] = c2;
    cube[4][6] = c1;

    ++turns_counter;
    Rotate(5, glParams.SPEED, -1);
}

void Cube::RR () {
    rotate_clockwise(2);
    char c1, c2, c3;
    c1 = cube[0][6];
    c2 = cube[0][7];
    c3 = cube[0][8];

    cube[0][6] = cube[1][8];
    cube[0][7] = cube[1][5];
    cube[0][8] = cube[1][2];

    cube[1][2] = cube[5][0];
    cube[1][5] = cube[5][1];
    cube[1][8] = cube[5][2];

    cube[5][0] = cube[3][6];
    cube[5][1] = cube[3][3];
    cube[5][2] = cube[3][0];

    cube[3][0] = c1;
    cube[3][3] = c2;
    cube[3][6] = c3;

    ++turns_counter;
    Rotate(1, glParams.SPEED, -1);
}

void Cube::OR () {
    rotate_clockwise(4);
    char c1, c2, c3;
    c1 = cube[0][0];
    c2 = cube[0][1];
    c3 = cube[0][2];

    cube[0][0] = cube[3][2];
    cube[0][1] = cube[3][5];
    cube[0][2] = cube[3][8];

    cube[3][2] = cube[5][8];
    cube[3][5] = cube[5][7];
    cube[3][8] = cube[5][6];

    cube[5][6] = cube[1][0];
    cube[5][7] = cube[1][3];
    cube[5][8] = cube[1][6];

    cube[1][0] = c3;
    cube[1][3] = c2;
    cube[1][6] = c1;

    ++turns_counter;
    Rotate(0, glParams.SPEED, 1);
}

void Cube::BR () {
    rotate_clockwise(1);
    char c1, c2, c3;
    c1 = cube[0][0];
    c2 = cube[0][3];
    c3 = cube[0][6];

    cube[0][0] = cube[4][8];
    cube[0][3] = cube[4][5];
    cube[0][6] = cube[4][2];

    cube[4][2] = cube[5][6];
    cube[4][5] = cube[5][3];
    cube[4][8] = cube[5][0];

    cube[5][0] = cube[2][0];
    cube[5][3] = cube[2][3];
    cube[5][6] = cube[2][6];

    cube[2][0] = c1;
    cube[2][3] = c2;
    cube[2][6] = c3;

    ++turns_counter;
    Rotate(4, glParams.SPEED, 1);
}

void Cube::YR () {
    GR();
}

void Cube::WR () {
    GR();
}

void Cube::GL () {
    BR();
}

void Cube::RL () {
    OR();
}

void Cube::OL () {
    RR();
}

void Cube::BL () {
    GR();
}

void Cube::YL () {
    RL();
}

void Cube::WL () {
    RL();
}

void Cube::GRb () {
    rotate_counterclockwise(3);
    char c1, c2, c3;
    c1 = cube[0][2];
    c2 = cube[0][5];
    c3 = cube[0][8];

    cube[0][2] = cube[4][6];
    cube[0][5] = cube[4][3];
    cube[0][8] = cube[4][0];

    cube[4][0] = cube[5][8];
    cube[4][3] = cube[5][5];
    cube[4][6] = cube[5][2];

    cube[5][2] = cube[2][2];
    cube[5][5] = cube[2][5];
    cube[5][8] = cube[2][8];

    cube[2][2] = c1;
    cube[2][5] = c2;
    cube[2][8] = c3;

    ++turns_counter;
    Rotate(5, glParams.SPEED, 1);
}

void Cube::RRb () {
    rotate_counterclockwise(2);
    char c1, c2, c3;
    c1 = cube[0][6];
    c2 = cube[0][7];
    c3 = cube[0][8];

    cube[0][6] = cube[3][0];
    cube[0][7] = cube[3][3];
    cube[0][8] = cube[3][6];

    cube[3][0] = cube[5][2];
    cube[3][3] = cube[5][1];
    cube[3][6] = cube[5][0];

    cube[5][0] = cube[1][2];
    cube[5][1] = cube[1][5];
    cube[5][2] = cube[1][8];

    cube[1][2] = c3;
    cube[1][5] = c2;
    cube[1][8] = c1;

    ++turns_counter;
    Rotate(1, glParams.SPEED, 1);
}

void Cube::ORb () {
    rotate_counterclockwise(4);
    char c1, c2, c3;
    c1 = cube[0][0];
    c2 = cube[0][1];
    c3 = cube[0][2];

    cube[0][0] = cube[1][6];
    cube[0][1] = cube[1][3];
    cube[0][2] = cube[1][0];

    cube[1][0] = cube[5][6];
    cube[1][3] = cube[5][7];
    cube[1][6] = cube[5][8];

    cube[5][6] = cube[3][8];
    cube[5][7] = cube[3][5];
    cube[5][8] = cube[3][2];

    cube[3][2] = c1;
    cube[3][5] = c2;
    cube[3][8] = c3;

    ++turns_counter;
    Rotate(0, glParams.SPEED, -1);
}

void Cube::BRb () {
    rotate_counterclockwise(1);
    char c1, c2, c3;
    c1 = cube[0][0];
    c2 = cube[0][3];
    c3 = cube[0][6];

    cube[0][0] = cube[2][0];
    cube[0][3] = cube[2][3];
    cube[0][6] = cube[2][6];

    cube[2][0] = cube[5][0];
    cube[2][3] = cube[5][3];
    cube[2][6] = cube[5][6];

    cube[5][0] = cube[4][8];
    cube[5][3] = cube[4][5];
    cube[5][6] = cube[4][2];

    cube[4][2] = c3;
    cube[4][5] = c2;
    cube[4][8] = c1;

    ++turns_counter;
    Rotate(4, glParams.SPEED, -1);
}

void Cube::YRb () {
    GRb();
}

void Cube::WRb () {
    GRb();
}

void Cube::GLb () {
    BRb();
}

void Cube::RLb () {
    ORb();
}

void Cube::OLb () {
    RRb();
}

void Cube::BLb () {
    GRb();
}

void Cube::YLb () {
    GLb();
}

void Cube::WLb () {
    GLb();
}

void Cube::GU () {
    rotate_clockwise(0);
    char c1, c2, c3;
    c1 = cube[2][0];
    c2 = cube[2][1];
    c3 = cube[2][2];

    cube[2][0] = cube[3][0];
    cube[2][1] = cube[3][1];
    cube[2][2] = cube[3][2];

    cube[3][0] = cube[4][0];
    cube[3][1] = cube[4][1];
    cube[3][2] = cube[4][2];

    cube[4][0] = cube[1][0];
    cube[4][1] = cube[1][1];
    cube[4][2] = cube[1][2];

    cube[1][0] = c1;
    cube[1][1] = c2;
    cube[1][2] = c3;

    ++turns_counter;
    Rotate(3, glParams.SPEED, -1);
}

void Cube::RU () {
    GU ();
}

void Cube::OU () {
    GU ();
}

void Cube::BU () {
    GU ();
}

void Cube::YU () {
    OR();
}

void Cube::WU () {
    RR();
}

void Cube::GUb () {
    rotate_counterclockwise(0);
    char c1, c2, c3;
    c1 = cube[2][0];
    c2 = cube[2][1];
    c3 = cube[2][2];

    cube[2][0] = cube[1][0];
    cube[2][1] = cube[1][1];
    cube[2][2] = cube[1][2];

    cube[1][0] = cube[4][0];
    cube[1][1] = cube[4][1];
    cube[1][2] = cube[4][2];

    cube[4][0] = cube[3][0];
    cube[4][1] = cube[3][1];
    cube[4][2] = cube[3][2];

    cube[3][0] = c1;
    cube[3][1] = c2;
    cube[3][2] = c3;

    ++turns_counter;
    Rotate(3, glParams.SPEED, 1);
}

void Cube::RUb () {
    GUb();
}

void Cube::OUb () {
    GUb();
}

void Cube::BUb () {
    GUb();
}

void Cube::YUb () {
    RLb();
}

void Cube::WUb () {
    RRb();
}

void Cube::GD () {
    rotate_clockwise(5);
    char c1, c2, c3;
    c1 = cube[2][6];
    c2 = cube[2][7];
    c3 = cube[2][8];

    cube[2][6] = cube[1][6];
    cube[2][7] = cube[1][7];
    cube[2][8] = cube[1][8];

    cube[1][6] = cube[4][6];
    cube[1][7] = cube[4][7];
    cube[1][8] = cube[4][8];

    cube[4][6] = cube[3][6];
    cube[4][7] = cube[3][7];
    cube[4][8] = cube[3][8];

    cube[3][6] = c1;
    cube[3][7] = c2;
    cube[3][8] = c3;

    ++turns_counter;
    Rotate(2, glParams.SPEED, 1);
}

void Cube::RD () {
    GD();
}

void Cube::OD () {
    GD();
}

void Cube::BD () {
    GD();
}

void Cube::YD () {
    RR();
}

void Cube::WD () {
    RL();
}

void Cube::GDb () {
    rotate_counterclockwise(5);
    char c1, c2, c3;
    c1 = cube[2][6];
    c2 = cube[2][7];
    c3 = cube[2][8];

    cube[2][6] = cube[3][6];
    cube[2][7] = cube[3][7];
    cube[2][8] = cube[3][8];

    cube[3][6] = cube[4][6];
    cube[3][7] = cube[4][7];
    cube[3][8] = cube[4][8];

    cube[4][6] = cube[1][6];
    cube[4][7] = cube[1][7];
    cube[4][8] = cube[1][8];

    cube[1][6] = c1;
    cube[1][7] = c2;
    cube[1][8] = c3;

    ++turns_counter;
    Rotate(2, glParams.SPEED, -1);
}

void Cube::RDb () {
    GDb();
}

void Cube::ODb () {
    GDb();
}

void Cube::BDb () {
    GDb();
}

void Cube::YDb () {
    OLb();
}

void Cube::WDb () {
    ORb();
}

void Cube::GF () {
    RR();
}

void Cube::RF () {
    BR();
}

void Cube::OF () {
    GR();
}

void Cube::BF () {
    OR();
}

void Cube::YF () {
    GU();
}

void Cube::WF () {
    GD();
}

void Cube::GFb () {
    RRb();
}

void Cube::OFb () {
    GRb();
}

void Cube::RFb () {
    BRb();
}

void Cube::BFb () {
    ORb();
}

void Cube::YFb () {
    GUb();
}

void Cube::WFb () {
    GDb();
}

void Cube::GB () {
    OR();
}

void Cube::RB () {
    GR();
}

void Cube::OB () {
    BR();
}

void Cube::BB () {
    RR();
}

void Cube::YB () {
    GD();
}

void Cube::WB () {
    GU();
}

void Cube::GBb () {
    ORb();
}

void Cube::RBb () {
    GRb();
}

void Cube::OBb () {
    BRb();
}

void Cube::BBb () {
    RRb();
}

void Cube::YBb () {
    GDb();
}

void Cube::WBb () {
    GUb();
}

void Cube::RotateGR() {
    GR();
}
void Cube::RotateGL() {
    GL();
}
void Cube::RotateGU() {
    GU();
}
void Cube::RotateGF() {
    GF();
}
void Cube::RotateGB() {
    GB();
}
void Cube::RotateGD() {
    GD();
}

Cube::~Cube() {}

void Cube::cross_manage(char first_colour, char second_colour) {
    if (first_colour == 'r') {
        if (checker.check_cross(cube)) {
            return;
        }

        for (int k = 0; k < 3; ++k) {
            if (cube[1][1] != first_colour || cube[0][3] != second_colour || cube[1][1] != cube[1][4]) {
                if (checker.check_cross(cube))
                    return;
                steps += "RU ";
                RU();
            }
            else {
                break;
            }
        }

        if (checker.check_cross(cube)) {
            return;
        }
        steps += "RF RF ";
        RF();
        RF();
    }

    else if (first_colour == 'g') {
        if (checker.check_cross(cube)) {
            return;
        }
        for (int k = 0; k < 3; ++k) {
            if (cube[2][1] != first_colour || cube[0][7] != second_colour || cube[2][1] != cube[2][4]) {
                if (checker.check_cross(cube))
                    return;
                steps += "GU ";
                GU();
            }
            else {
                break;
            }
        }

        if (checker.check_cross(cube)) {
            return;
        }
        steps += "GF GF ";
        GF();
        GF();
    }

    else if (first_colour == 'o') {
        if (checker.check_cross(cube)) {
            return;
        }
        for (int k = 0; k < 3; ++k) {
            if (cube[3][1] != first_colour || cube[0][5] != second_colour || cube[3][1] != cube[3][4]) {
                if (checker.check_cross(cube)) {
                    return;
                }
                steps += "OU ";
                OU();
            }
            else {
                break;
            }
        }

        if (checker.check_cross(cube)) {
            return;
        }
        steps += "OF OF ";
        OF();
        OF();
    }

    else if (first_colour == 'b') {
        if (checker.check_cross(cube)) {
            return;
        }
        for (int k = 0; k < 3; ++k) {
            if (cube[4][1] != first_colour || cube[0][1] != second_colour || cube[4][1] != cube[4][4]) {
                if (checker.check_cross(cube)) {
                    return;
                }
                steps += "BU ";
                BU();
            }
            else {
                break;
            }
        }

        if (checker.check_cross(cube)) {
            return;
        }
        steps += "BF BF ";
        BF();
        BF();
    }
}

void Cube::solve_white_cross() {
    char another_colour, white_colour;
    int counter = 0;
    while ((!checker.check_cross(cube)) && (counter < max_steps_per_try)) {
        for (int k = 0; k < 9; ++k) {
            another_colour = cube[4][1]; //white
            white_colour = cube[0][1];

            if (white_colour == 'w') {
                cross_manage(another_colour, white_colour);
            }
            another_colour = cube[1][1];
            white_colour = cube[0][3];

            if (white_colour == 'w') {
                cross_manage(another_colour, white_colour);
            }
            another_colour = cube[3][1];
            white_colour = cube[0][5];

            if (white_colour == 'w') {
                cross_manage(another_colour, white_colour);
            }
            another_colour = cube[2][1];
            white_colour = cube[0][7];

            if (white_colour == 'w') {
                cross_manage(another_colour, white_colour);
            }
            another_colour = cube[0][3]; // red
            white_colour = cube[1][1];

            if (white_colour == 'w') {
                steps += "RF RR RU RRb ";
                RF();
                RR();
                RU();
                RRb();
                cross_manage(another_colour, white_colour);
            }
            another_colour = cube[4][5];
            white_colour = cube[1][3];

            if (white_colour == 'w') {
                steps += "RLb RUb RL ";
                RLb();
                RUb();
                RL();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[2][3];
            white_colour = cube[1][5];
            if (white_colour == 'w') {
                steps += "RR RU RRb ";
                RR();
                RU();
                RRb();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[5][3];
            white_colour = cube[1][7];
            if (white_colour == 'w') {
                steps += "RF RLb RUb RL ";
                RF();
                RLb();
                RUb();
                RL();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[0][7]; //green
            white_colour = cube[2][1];
            if (white_colour == 'w') {
                steps += "GF GR GU GRb ";
                GF();
                GR();
                GU();
                GRb();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[1][5];
            white_colour = cube[2][3];
            if (white_colour == 'w') {
                steps += "GLb GUb GL ";
                GLb();
                GUb();
                GL();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[3][3];
            white_colour = cube[2][5];
            if (white_colour == 'w') {
                steps += "GR GU GRb ";
                GR();
                GU();
                GRb();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[5][1];
            white_colour = cube[2][7];
            if (white_colour == 'w') {
                steps += "GF GLb GUb GL ";
                GF();
                GLb();
                GUb();
                GL();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[0][5]; // orange
            white_colour = cube[3][1];
            if (white_colour == 'w') {
                steps += "OF OR OU ORb ";
                OF();
                OR();
                OU();
                ORb();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[2][5];
            white_colour = cube[3][3];
            if (white_colour == 'w') {
                steps += "OLb OUb OL ";
                OLb();
                OUb();
                OL();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[4][3];
            white_colour = cube[3][5];
            if (white_colour == 'w') {
                steps += "OR OU ORb ";
                OR();
                OU();
                ORb();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[5][5];
            white_colour = cube[3][7];
            if (white_colour == 'w') {
                steps += "OF OLb OUb OL ";
                OF();
                OLb();
                OUb();
                OL();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[0][1]; //blue
            white_colour = cube[4][1];
            if (white_colour == 'w') {
                steps += "BF BR BU BRb ";
                BF();
                BR();
                BU();
                BRb();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[3][5];
            white_colour = cube[4][3];
            if (white_colour == 'w') {
                steps += "BLb BUb BL ";
                BLb();
                BUb();
                BL();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[1][3];
            white_colour = cube[4][5];
            if (white_colour == 'w') {
                steps += "BR BU BRb ";
                BR();
                BU();
                BRb();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[5][7];
            white_colour = cube[4][7];
            if (white_colour == 'w') {
                steps += "BF BLb BUb BL ";
                BF();
                BLb();
                BUb();
                BL();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[2][7]; //white
            white_colour = cube[5][1];
            if (white_colour == 'w' && another_colour != cube[2][4]) {
                steps += "GF GF ";
                GF();
                GF();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[1][7];
            white_colour = cube[5][3];
            if (white_colour == 'w' && another_colour != cube[1][4]) {
                steps += "RF RF ";
                RF();
                RF();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[3][7];
            white_colour = cube[5][5];
            if (white_colour == 'w' && another_colour != cube[3][4]) {
                steps += "OF OF ";
                OF();
                OF();
                cross_manage(another_colour, white_colour);
            }

            another_colour = cube[4][7];
            white_colour = cube[5][7];
            if (white_colour == 'w' && another_colour != cube[4][4]) {
                steps += "OF OF ";
                OF();
                OF();
                cross_manage(another_colour, white_colour);
            }
        }
        counter++;
    }
    if (counter >= max_steps_per_try) {
        std::cout << "I couldn't solve this cube. Maybe my algorithm is shit" << counter << std::endl;
    }
    else {
        std::cout << "White crosses solved: " << counter << std::endl;
    }
}

void Cube::solve_yellow_cross() {
    int counter = 0;
    while ((!checker.check_yellow_cross(cube)) && (counter < 100)) {
        if (cube[0][1] == 'y' && cube[0][3] == 'y' && cube[0][5] != 'y' && cube[0][7] != 'y') {
            turn_yellow(1);
        }
        else if (cube[0][1] == 'y' && cube[0][3] != 'y' && cube[0][5] == 'y' && cube[0][7] != 'y') {
            steps += "GUb ";
            GUb();
            turn_yellow(1);
        }
        else if (cube[0][1] != 'y' && cube[0][3] != 'y' && cube[0][5] == 'y' && cube[0][7] == 'y') {
            steps += "GUb GUb ";
            GUb();
            GUb();
            turn_yellow(1);
        }
        else if (cube[0][1] != 'y' && cube[0][3] == 'y' && cube[0][5] != 'y' && cube[0][7] == 'y') {
            steps += "GU ";
            GU();
            turn_yellow(1);
        }
        else if (cube[0][1] != 'y' && cube[0][3] == 'y' && cube[0][5] == 'y' && cube[0][7] != 'y') {
            turn_yellow(2);
        }
        else if (cube[0][1] == 'y' && cube[0][3] != 'y' && cube[0][5] != 'y' && cube[0][7] == 'y') {
            steps += "GU ";
            GU();
            turn_yellow(2);
        }
        else if (cube[0][1] != 'y' && cube[0][3] != 'y' && cube[0][5] != 'y' && cube[0][7] != 'y') {
            turn_yellow(1);
            steps += "GU ";
            GU();
            turn_yellow(2);
        }
        else if (cube[0][1] == 'y' && cube[0][3] == 'y' && cube[0][5] == 'y' && cube[0][7] == 'y') {
            break;
        }
        counter++;
    }
    if (counter >= 100) {
        std::cout << "I couldn't solve this cube. Maybe my algorithm is shit" << counter << std::endl;
    }
    else {
        std::cout << "Yellow crosses solved: " << counter << std::endl;
    }
}

void Cube::solve_right_yellow_cross() {
    int counter = 0;
    while ((!checker.check_right_yellow_cross(cube)) || (counter < 100)) {
        while (true) {
            if (cube[1][1] == 'r' && cube[2][1] == 'g' && cube[3][1] == 'o' && cube[4][1] == 'b') {
                break;
            }
            else if (cube[1][1] == 'r' && cube[2][1] == 'g' && cube[3][1] != 'o' && cube[4][1] != 'b') {
                break;
            }
            else if (cube[1][1] == 'r' && cube[2][1] != 'g' && cube[3][1] == 'o' && cube[4][1] != 'b') {
                break;
            }
            else if (cube[1][1] == 'r' && cube[2][1] != 'g' && cube[3][1] != 'o' && cube[4][1] == 'b') {
                break;
            }
            else if (cube[1][1] == 'r' && cube[2][1] == 'g' && cube[3][1] != 'o' && cube[4][1] != 'b') {
                break;
            }
            else if (cube[1][1] != 'r' && cube[2][1] == 'g' && cube[3][1] == 'o' && cube[4][1] != 'b') {
                break;
            }
            else if (cube[1][1] != 'r' && cube[2][1] == 'g' && cube[3][1] != 'o' && cube[4][1] == 'b') {
                break;
            }
            else if (cube[1][1] == 'r' && cube[2][1] != 'g' && cube[3][1] == 'o' && cube[4][1] != 'b') {
                break;
            }
            else if (cube[1][1] != 'r' && cube[2][1] == 'g' && cube[3][1] == 'o' && cube[4][1] != 'b') {
                break;
            }
            else if (cube[1][1] != 'r' && cube[2][1] != 'g' && cube[3][1] == 'o' && cube[4][1] == 'b') {
                break;
            }
            else if (cube[1][1] == 'r' && cube[2][1] != 'g' && cube[3][1] != 'o' && cube[4][1] == 'b') {
                break;
            }
            else if (cube[1][1] != 'r' && cube[2][1] == 'g' && cube[3][1] != 'o' && cube[4][1] == 'b') {
                break;
            }
            else if (cube[1][1] != 'r' && cube[2][1] != 'g' && cube[3][1] == 'o' && cube[4][1] == 'b') {
                break;
            }
            else {
                steps += "GU ";
                GU();
            }
        }

        if (cube[1][1] == 'r' && cube[2][1] == 'g' && cube[3][1] == 'o' && cube[4][1] == 'b') {
            break;
        }

        else if (cube[1][1] == 'r' && cube[2][1] == 'g' && cube[3][1] != 'o' && cube[4][1] != 'b') {
            turn_yellow_edgeB('l');
        }
        else if (cube[1][1] == 'r' && cube[2][1] != 'g' && cube[3][1] == 'o' && cube[4][1] != 'b') {
            turn_yellow_edgeG('c');
        }
        else if (cube[1][1] == 'r' && cube[2][1] != 'g' && cube[3][1] != 'o' && cube[4][1] == 'b') {
            turn_yellow_edgeG('r');
        }

        else if (cube[1][1] == 'r' && cube[2][1] == 'g' && cube[3][1] != 'o' && cube[4][1] != 'b') {
            turn_yellow_edgeB('l');
        }
        else if (cube[1][1] != 'r' && cube[2][1] == 'g' && cube[3][1] == 'o' && cube[4][1] != 'b') {
            turn_yellow_edgeR('l');
        }
        else if (cube[1][1] != 'r' && cube[2][1] == 'g' && cube[3][1] != 'o' && cube[4][1] == 'b') {
            turn_yellow_edgeR('c');
        }

        else if (cube[1][1] == 'r' && cube[2][1] != 'g' && cube[3][1] == 'o' && cube[4][1] != 'b') {
            turn_yellow_edgeG('c');
        }
        else if (cube[1][1] != 'r' && cube[2][1] == 'g' && cube[3][1] == 'o' && cube[4][1] != 'b') {
            turn_yellow_edgeR('l');
        }
        else if (cube[1][1] != 'r' && cube[2][1] != 'g' && cube[3][1] == 'o' && cube[4][1] == 'b') {
            turn_yellow_edgeR('r');
        }

        else if (cube[1][1] == 'r' && cube[2][1] != 'g' && cube[3][1] != 'o' && cube[4][1] == 'b') {
            turn_yellow_edgeG('l');
        }
        else if (cube[1][1] != 'r' && cube[2][1] == 'g' && cube[3][1] != 'o' && cube[4][1] == 'b') {
            turn_yellow_edgeR('c');
        }
        else if (cube[1][1] != 'r' && cube[2][1] != 'g' && cube[3][1] == 'o' && cube[4][1] == 'b') {
            turn_yellow_edgeR('r');
        }
        counter++;
    }
    if (counter >= 100) {
        std::cout << "I couldn't solve this cube. Maybe my algorithm is shit" << counter << std::endl;
    }
    else {
        std::cout << "Right yellow crosses solved: " << counter << std::endl;
    }
}

void Cube::solve_right_yellow_angle() {
    int counter = 0;
    while ((!checker.is_assembled(cube)) || (counter < max_steps_per_try)) {
        for (int k = 0; k < 4; ++k) {
            if (cube[1][0] == 'g' && cube[4][2] == 'r' && cube[0][0] == 'y') {
                steps += "RFb RLb RF RRb RFb RL RF RR ";
                RFb();
                RLb();
                RF();
                RRb();
                RFb();
                RL();
                RF();
                RR();
            }
            if (cube[3][0] == 'g' && cube[2][2] == 'r' && cube[0][8] == 'y') {
                steps += "OLb OBb ORb OB OL OBb OR OB ";
                OLb();
                OBb();
                ORb();
                OB();
                OL();
                OBb();
                OR();
                OB();
            }
            if (cube[3][2] == 'r' && cube[4][0] == 'g' && cube[0][2] == 'y') {
                steps += "OBb ORb OFb OR OB ORb OF OR ";
                OBb();
                ORb();
                OFb();
                OR();
                OB();
                ORb();
                OF();
                OR();
            }
            if (cube[1][0] == 'o' && cube[4][2] == 'g' && cube[0][0] == 'y') {
                steps += "RBb RRb RB RLb RBb RR RB RL ";
                RBb();
                RRb();
                RB();
                RLb();
                RBb();
                RR();
                RB();
                RL();
            }
            if (cube[3][2] == 'g' && cube[4][0] == 'o' && cube[0][2] == 'y') {
                steps += "ORb OFb OLb OF OR OFb OL OF ";
                ORb();
                OFb();
                OLb();
                OF();
                OR();
                OFb();
                OL();
                OF();
            }
        }
        for (int k = 0; k < 4; ++k) {
            if (cube[3][0] == 'y') {
                steps += "GFb GR GF GRb GFb GR GF GRb GU ";
                GFb();
                GR();
                GF();
                GRb();
                GFb();
                GR();
                GF();
                GRb();
                GU();
            }
            else if (cube[2][2] == 'y') {
                steps += "GR GFb GRb GF GR GFb GRb GF GU ";
                GR();
                GFb();
                GRb();
                GF();
                GR();
                GFb();
                GRb();
                GF();
                GU();
            }
            else {
                if (!checker.is_assembled(cube)) {
                    steps += "111GU ";
                    GU();
                }
                else {
                    break;
                }
            }
        }

        for (int k = 0; k < 4; ++k) {
            if (cube[2][1] == 'g') {
                break;
            }
            else {
                steps += "GU ";
                GU();
            }
        }

        if (checker.is_assembled(cube)) {
            break;
        }
        counter++;
    }

    if (counter >= max_steps_per_try) {
        std::cout << "I couldn't solve this cube. Maybe my algorithm is shit" << counter << std::endl;
    }
    else {
        std::cout << "Right yellow angles solved: " << counter << std::endl;
    }
}

void Cube::solve_white_angle() {
    int counter = 0;
    while ((!checker.check_white_angle(cube)) && (counter < max_steps_per_try)) {
        char first_colour, second_colour, third_colour;
        for (int k = 0; k < 4; ++k) {
            first_colour = cube[1][8]; //red
            second_colour = cube[2][6];
            third_colour = cube[5][0];
            if ((cube[1][8] == 'r') && (cube[2][6] == 'g') && (cube[5][0] == 'w')) {
                break;
            }
            else if ((first_colour == 'w') && (second_colour == 'r') && (third_colour == 'g')) {
                steps += "RU RR RUb RRb RU RR RUb RRb ";
                RU();
                RR();
                RUb();
                RRb();
                RU();
                RR();
                RUb();
                RRb();
                break;
            }
            else if ((first_colour == 'g') && (second_colour == 'w') && (third_colour == 'r')) {
                steps += "RR RU RRb RUb RR RU RRb RUb ";
                RR();
                RU();
                RRb();
                RUb();
                RR();
                RU();
                RRb();
                RUb();
                break;
            }
            else if ((first_colour == 'w') || (second_colour == 'w') || (third_colour == 'w')) {
                steps += "RR RU RRb RUb ";
                RR();
                RU();
                RRb();
                RUb();
            }
        }

        for (int k = 0; k < 4; ++k) {
            first_colour = 'r';
            second_colour = 'g';
            third_colour = 'w';
            if ((cube[1][8] == 'r') && (cube[2][6] == 'g') && (cube[5][0] == 'w')) {
                break;
            }
            if (cube[1][2] == third_colour && cube[2][0] == second_colour && cube[0][6] == first_colour) {
                turn_red_angle(cube[1][2], cube[2][0], cube[0][6]);
            }
            if (cube[1][2] == second_colour && cube[2][0] == first_colour && cube[0][6] == third_colour) {
                turn_red_angle(cube[1][2], cube[2][0], cube[0][6]);
            }
            if (cube[1][2] == first_colour && cube[2][0] == third_colour && cube[0][6] == second_colour) {
                turn_red_angle(cube[1][2], cube[2][0], cube[0][6]);
            }

            if (cube[2][2] == third_colour && cube[3][0] == second_colour && cube[0][8] == first_colour) {
                steps += "RU ";
                RU();
                turn_red_angle(cube[2][2], cube[3][0], cube[0][8]);
            }
            if (cube[2][2] == second_colour && cube[3][0] == first_colour && cube[0][8] == third_colour) {
                steps += "RU ";
                RU();
                turn_red_angle(cube[2][2], cube[3][0], cube[0][8]);
            }
            if (cube[2][2] == first_colour && cube[3][0] == third_colour && cube[0][8] == second_colour) {
                steps += "RU ";
                RU();
                turn_red_angle(cube[2][2], cube[3][0], cube[0][8]);
            }

            if (cube[3][2] == third_colour && cube[4][0] == second_colour && cube[0][2] == first_colour) {
                steps += "RUb RUb ";
                RUb();
                RUb();
                turn_red_angle(cube[3][2], cube[4][0], cube[0][2]);
            }
            if (cube[3][2] == second_colour && cube[4][0] == first_colour && cube[0][2] == third_colour) {
                steps += "RUb RUb ";
                RUb();
                RUb();
                turn_red_angle(cube[3][2], cube[4][0], cube[0][2]);
            }
            if (cube[3][2] == first_colour && cube[4][0] == third_colour && cube[0][2] == second_colour) {
                steps += "RUb RUb ";
                RUb();
                RUb();
                turn_red_angle(cube[3][2], cube[4][0], cube[0][2]);
            }

            if (cube[4][2] == third_colour && cube[1][0] == second_colour && cube[0][0] == first_colour) {
                steps += "RUb ";
                RUb();
                turn_red_angle(cube[4][2], cube[1][0], cube[0][0]);
            }
            if (cube[4][2] == second_colour && cube[1][0] == first_colour && cube[0][0] == third_colour) {
                steps += "RUb ";
                RUb();
                turn_red_angle(cube[4][2], cube[1][0], cube[0][0]);
            }
            if (cube[4][2] == first_colour && cube[1][0] == third_colour && cube[0][0] == second_colour) {
                steps += "RUb ";
                RUb();
                turn_red_angle(cube[4][2], cube[1][0], cube[0][0]);
            }

        }

        for (int k = 0; k < 4; ++k) {
            first_colour = cube[2][8]; //green
            second_colour = cube[3][6];
            third_colour = cube[5][2];
            if ((cube[2][8] == 'g') && (cube[3][6] == 'o') && (cube[5][2] == 'w')) {
                break;
            }
            else if ((first_colour == 'w') && (second_colour == 'g') && (third_colour == 'o')) {
                steps += "GU GR GUb GRb GU GR GUb GRb ";
                GU();
                GR();
                GUb();
                GRb();
                GU();
                GR();
                GUb();
                GRb();
                break;
            }
            else if ((first_colour == 'o') && (second_colour == 'w') && (third_colour == 'g')) {
                steps += "GR GU GRb GUb GR GU GRb GUb ";
                GR();
                GU();
                GRb();
                GUb();
                GR();
                GU();
                GRb();
                GUb();
                break;
            }
            else if ((first_colour == 'w') || (second_colour == 'w') || (third_colour == 'w')) {
                steps += "GR GU GRb GUb ";
                GR();
                GU();
                GRb();
                GUb();
            }
        }

        for (int k = 0; k < 4; ++k) {
            first_colour = 'g';
            second_colour = 'o';
            third_colour = 'w';
            if ((cube[2][8] == 'g') && (cube[3][6] == 'o') && (cube[5][2] == 'w')) {
                break;
            }
            if (cube[1][2] == third_colour && cube[2][0] == second_colour && cube[0][6] == first_colour) {
                steps += "RUb ";
                RUb();
                turn_green_angle(cube[1][2], cube[2][0], cube[0][6]);
            }
            if (cube[1][2] == second_colour && cube[2][0] == first_colour && cube[0][6] == third_colour) {
                steps += "RUb ";
                RUb();
                turn_green_angle(cube[1][2], cube[2][0], cube[0][6]);
            }
            if (cube[1][2] == first_colour && cube[2][0] == third_colour && cube[0][6] == second_colour) {
                steps += "RUb ";
                RUb();
                turn_green_angle(cube[1][2], cube[2][0], cube[0][6]);
            }

            if (cube[2][2] == third_colour && cube[3][0] == second_colour && cube[0][8] == first_colour) {
                turn_green_angle(cube[2][2], cube[3][0], cube[0][8]);
            }
            if (cube[2][2] == second_colour && cube[3][0] == first_colour && cube[0][8] == third_colour) {
                turn_green_angle(cube[2][2], cube[3][0], cube[0][8]);
            }
            if (cube[2][2] == first_colour && cube[3][0] == third_colour && cube[0][8] == second_colour) {
                turn_green_angle(cube[2][2], cube[3][0], cube[0][8]);
            }

            if (cube[3][2] == third_colour && cube[4][0] == second_colour && cube[0][2] == first_colour) {
                steps += "GUb ";
                GUb();
                turn_green_angle(cube[3][2], cube[4][0], cube[0][2]);
            }
            if (cube[3][2] == second_colour && cube[4][0] == first_colour && cube[0][2] == third_colour) {
                steps += "GUb ";
                GUb();
                turn_green_angle(cube[3][2], cube[4][0], cube[0][2]);
            }
            if (cube[3][2] == first_colour && cube[4][0] == third_colour && cube[0][2] == second_colour) {
                steps += "GUb ";
                GUb();
                turn_green_angle(cube[3][2], cube[4][0], cube[0][2]);
            }

            if (cube[4][2] == third_colour && cube[1][0] == second_colour && cube[0][0] == first_colour) {
                steps += "GUb GUb ";
                GUb();
                GUb();
                turn_green_angle(cube[4][2], cube[1][0], cube[0][0]);
            }
            if (cube[4][2] == second_colour && cube[1][0] == first_colour && cube[0][0] == third_colour) {
                steps += "GUb GUb ";
                GUb();
                GUb();
                turn_green_angle(cube[4][2], cube[1][0], cube[0][0]);
            }
            if (cube[4][2] == first_colour && cube[1][0] == third_colour && cube[0][0] == second_colour) {
                steps += "GUb GUb ";
                GUb();
                GUb();
                turn_green_angle(cube[4][2], cube[1][0], cube[0][0]);
            }
        }

        for (int k = 0; k < 4; ++k) {
            first_colour = cube[3][8]; //orange
            second_colour = cube[4][6];
            third_colour = cube[5][8];
            if ((cube[3][8] == 'o') && (cube[4][6] == 'b') && (cube[5][8] == 'w')) {
                break;
            }
            else if ((first_colour == 'w') && (second_colour == 'o') && (third_colour == 'b')) {
                steps += "OU OR OUb ORb OU OR OUb ORb ";
                OU();
                OR();
                OUb();
                ORb();
                OU();
                OR();
                OUb();
                ORb();
                break;
            }
            else if ((first_colour == 'b') && (second_colour == 'w') && (third_colour == 'o')) {
                steps += "OR OU ORb OUb OR OU ORb OUb ";
                OR();
                OU();
                ORb();
                OUb();
                OR();
                OU();
                ORb();
                OUb();
                break;
            }
            else if ((first_colour == 'w') || (second_colour == 'w') || (third_colour == 'w')) {
                steps += "OR OU ORb OUb ";
                OR();
                OU();
                ORb();
                OUb();
            }
        }

        for (int k = 0; k < 4; ++k) {
            first_colour = 'o';
            second_colour = 'b';
            third_colour = 'w';
            if ((cube[3][8] == 'o') && (cube[4][6] == 'b') && (cube[5][8] == 'w')) {
                break;
            }
            if (cube[1][2] == third_colour && cube[2][0] == second_colour && cube[0][6] == first_colour) {
                steps += "OUb OUb ";
                OUb();
                OUb();
                turn_orange_angle(cube[1][2], cube[2][0], cube[0][6]);
            }
            if (cube[1][2] == second_colour && cube[2][0] == first_colour && cube[0][6] == third_colour) {
                steps += "OUb OUb ";
                OUb();
                OUb();
                turn_orange_angle(cube[1][2], cube[2][0], cube[0][6]);
            }
            if (cube[1][2] == first_colour && cube[2][0] == third_colour && cube[0][6] == second_colour) {
                steps += "OUb OUb ";
                OUb();
                OUb();
                turn_orange_angle(cube[1][2], cube[2][0], cube[0][6]);
            }

            if (cube[2][2] == third_colour && cube[3][0] == second_colour && cube[0][8] == first_colour) {
                steps += "OUb ";
                OUb();
                turn_orange_angle(cube[2][2], cube[3][0], cube[0][8]);
            }
            if (cube[2][2] == second_colour && cube[3][0] == first_colour && cube[0][8] == third_colour) {
                steps += "OUb ";
                OUb();
                turn_orange_angle(cube[2][2], cube[3][0], cube[0][8]);
            }
            if (cube[2][2] == first_colour && cube[3][0] == third_colour && cube[0][8] == second_colour) {
                steps += "OUb ";
                OUb();
                turn_orange_angle(cube[2][2], cube[3][0], cube[0][8]);
            }

            if (cube[3][2] == third_colour && cube[4][0] == second_colour && cube[0][2] == first_colour) {
                turn_orange_angle(cube[3][2], cube[4][0], cube[0][2]);
            }
            if (cube[3][2] == second_colour && cube[4][0] == first_colour && cube[0][2] == third_colour) {
                turn_orange_angle(cube[3][2], cube[4][0], cube[0][2]);
            }
            if (cube[3][2] == first_colour && cube[4][0] == third_colour && cube[0][2] == second_colour) {
                turn_orange_angle(cube[3][2], cube[4][0], cube[0][2]);
            }

            if (cube[4][2] == third_colour && cube[1][0] == second_colour && cube[0][0] == first_colour) {
                steps += "OUb ";
                OUb();
                turn_orange_angle(cube[4][2], cube[1][0], cube[0][0]);
            }
            if (cube[4][2] == second_colour && cube[1][0] == first_colour && cube[0][0] == third_colour) {
                steps += "OUb ";
                OUb();
                turn_orange_angle(cube[4][2], cube[1][0], cube[0][0]);
            }
            if (cube[4][2] == first_colour && cube[1][0] == third_colour && cube[0][0] == second_colour) {
                steps += "OUb ";
                OUb();
                turn_orange_angle(cube[4][2], cube[1][0], cube[0][0]);
            }
        }

        for (int k = 0; k < 4; ++k) {
            first_colour = cube[4][8]; //blue
            second_colour = cube[1][6];
            third_colour = cube[5][6];
            if ((cube[4][8] == 'b') && (cube[1][6] == 'r') && (cube[5][6] == 'w')) {
                break;
            }
            else if ((first_colour == 'w') && (second_colour == 'b') && (third_colour == 'r')) {
                steps += "BU BR BUb BRb BU BR BUb BRb ";
                BU();
                BR();
                BUb();
                BRb();
                BU();
                BR();
                BUb();
                BRb();
                break;
            }
            else if ((first_colour == 'r') && (second_colour == 'w') && (third_colour == 'b')) {
                steps += "BR BU BRb BUb BR BU BRb BUb ";
                BR();
                BU();
                BRb();
                BUb();
                BR();
                BU();
                BRb();
                BUb();
                break;
            }
            else if ((first_colour == 'w') || (second_colour == 'w') || (third_colour == 'w')) {
                steps += "BR BU BRb BUb ";
                BR();
                BU();
                BRb();
                BUb();
            }
        }

        for (int k = 0; k < 4; ++k) {
            first_colour = 'b';
            second_colour = 'r';
            third_colour = 'w';
            if ((cube[4][8] == 'b') && (cube[1][6] == 'r') && (cube[5][6] == 'w')) {
                break;
            }
            if (cube[1][2] == third_colour && cube[2][0] == second_colour && cube[0][6] == first_colour) {
                steps += "BU ";
                BU();
                turn_blue_angle(cube[1][2], cube[2][0], cube[0][6]);
            }
            if (cube[1][2] == second_colour && cube[2][0] == first_colour && cube[0][6] == third_colour) {
                steps += "BU ";
                BU();
                turn_blue_angle(cube[1][2], cube[2][0], cube[0][6]);
            }
            if (cube[1][2] == first_colour && cube[2][0] == third_colour && cube[0][6] == second_colour) {
                steps += "BU ";
                BU();
                turn_blue_angle(cube[1][2], cube[2][0], cube[0][6]);
            }

            if (cube[2][2] == third_colour && cube[3][0] == second_colour && cube[0][8] == first_colour) {
                steps += "BUb BUb ";
                BUb();
                BUb();
                turn_blue_angle(cube[2][2], cube[3][0], cube[0][8]);
            }
            if (cube[2][2] == second_colour && cube[3][0] == first_colour && cube[0][8] == third_colour) {
                steps += "BUb BUb ";
                BUb();
                BUb();
                turn_blue_angle(cube[2][2], cube[3][0], cube[0][8]);
            }
            if (cube[2][2] == first_colour && cube[3][0] == third_colour && cube[0][8] == second_colour) {
                steps += "BUb BUb ";
                BUb();
                BUb();
                turn_blue_angle(cube[2][2], cube[3][0], cube[0][8]);
            }

            if (cube[3][2] == third_colour && cube[4][0] == second_colour && cube[0][2] == first_colour) {
                steps += "BUb ";
                BUb();
                turn_blue_angle(cube[3][2], cube[4][0], cube[0][2]);
            }
            if (cube[3][2] == second_colour && cube[4][0] == first_colour && cube[0][2] == third_colour) {
                steps += "BUb ";
                BUb();
                turn_blue_angle(cube[3][2], cube[4][0], cube[0][2]);
            }
            if (cube[3][2] == first_colour && cube[4][0] == third_colour && cube[0][2] == second_colour) {
                steps += "BUb ";
                BUb();
                turn_blue_angle(cube[3][2], cube[4][0], cube[0][2]);
            }

            if (cube[4][2] == third_colour && cube[1][0] == second_colour && cube[0][0] == first_colour) {
                turn_blue_angle(cube[4][2], cube[1][0], cube[0][0]);
            }
            if (cube[4][2] == second_colour && cube[1][0] == first_colour && cube[0][0] == third_colour) {
                turn_blue_angle(cube[4][2], cube[1][0], cube[0][0]);
            }
            if (cube[4][2] == first_colour && cube[1][0] == third_colour && cube[0][0] == second_colour) {
                turn_blue_angle(cube[4][2], cube[1][0], cube[0][0]);
            }
        }
        counter++;
    }

    if (counter >= max_steps_per_try) {
        std::cout << "I couldn't solve this cube. Maybe my algorithm is shit" << counter << std::endl;
    }
    else {
        std::cout << "White edges solved: " << counter << std::endl;
    }
}

void Cube::solve_f2l() {
    int counter = 0;
    while ((!checker.is_f2l(cube)) && (counter < max_steps_per_try)) {
        for (int k = 0; k < 4; ++k) {
            if ((cube[1][1] == 'r' && cube[0][3] == 'b') || (cube[1][1] == 'r' && cube[0][3] == 'g')) {
                turn_red_edge(cube[1][1], cube[0][3]);
            }
            else if ((cube[2][1] == 'g' && cube[0][7] == 'r') || (cube[2][1] == 'g' && cube[0][7] == 'o')) {
                turn_green_edge(cube[2][1], cube[0][7]);
            }
            else if ((cube[3][1] == 'o' && cube[0][5] == 'g') || (cube[3][1] == 'o' && cube[0][5] == 'b')) {
                turn_orange_edge(cube[3][1], cube[0][5]);
            }
            else if ((cube[4][1] == 'b' && cube[0][1] == 'o') || (cube[4][1] == 'b' && cube[0][1] == 'r')) {
                turn_blue_edge(cube[4][1], cube[0][1]);
            }
            else {
                steps += "GU ";
                GU();
            }
        }
        if ((cube[1][3] != 'r' || cube[4][5] != 'b') && (cube[1][3] != 'y' || cube[4][5] != 'y')) {
            turn_red_edge('r', 'b');
        }
        if ((cube[1][5] != 'r' || cube[2][3] != 'g') && (cube[1][5] != 'y' || cube[2][3] != 'y')) {
            turn_red_edge('r', 'g');
        }

        if ((cube[2][3] != 'g' || cube[1][5] != 'r') && (cube[2][3] != 'y' || cube[1][5] != 'y')) {
            turn_green_edge('g', 'r');
        }
        if ((cube[2][5] != 'g' || cube[3][3] != 'o') && (cube[2][5] != 'y' || cube[3][3] != 'y')) {
            turn_green_edge('g', 'o');
        }

        if ((cube[3][3] != 'o' || cube[2][5] != 'g') && (cube[3][3] != 'y' || cube[2][5] != 'y')) {
            turn_orange_edge('o', 'g');
        }
        if ((cube[3][5] != 'o' || cube[4][3] != 'b') && (cube[3][5] != 'y' || cube[4][3] != 'y')) {
            turn_orange_edge('o', 'b');
        }

        if ((cube[4][3] != 'b' || cube[3][5] != 'o') && (cube[4][3] != 'y' || cube[3][5] != 'y')) {
            turn_blue_edge('b', 'o');
        }
        if ((cube[4][5] != 'b' || cube[1][3] != 'r') && (cube[4][5] != 'y' || cube[1][3] != 'y')) {
            turn_blue_edge('b', 'r');
        }

        counter++;
    }
    if (counter >= max_steps_per_try) {
        std::cout << "I couldn't solve this cube. Maybe my algorithm is shit" << counter << std::endl;
    }
    else {
        std::cout << "F2L:  " << counter << std::endl;
    }
}

void Cube::turn_red_angle(char first_colour, char second_colour, char third_colour) {
    if ((first_colour == 'w') && (second_colour == 'g') && (third_colour == 'r')) {
        steps += "RU RR RUb RRb ";
        RU();
        RR();
        RUb();
        RRb();
    }
    if ((first_colour == 'r') && (second_colour == 'w') && (third_colour == 'g')) {
        steps += "RR RU RRb RUb ";
        RR();
        RU();
        RRb();
        RUb();
    }
    if ((first_colour == 'g') && (second_colour == 'r') && (third_colour == 'w')) {
        steps += "RR RU RRb RUb RR RU RRb RUb RR RU RRb RUb ";
        RR();
        RU();
        RRb();
        RUb();
        RR();
        RU();
        RRb();
        RUb();
        RR();
        RU();
        RRb();
        RUb();
    }
}

void Cube::turn_green_angle(char first_colour, char second_colour, char third_colour) {
    if ((first_colour == 'w') && (second_colour == 'o') && (third_colour == 'g')) {
        steps += "GU GR GUb GRb ";
        GU();
        GR();
        GUb();
        GRb();
    }
    else if ((first_colour == 'g') && (second_colour == 'w') && (third_colour == 'o')) {
        steps += "GR GU GRb GUb ";
        GR();
        GU();
        GRb();
        GUb();
    }
    if ((first_colour == 'o') && (second_colour == 'g') && (third_colour == 'w')) {
        steps += "GR GU GRb GUb GR GU GRb GUb GR GU GRb GUb ";
        GR();
        GU();
        GRb();
        GUb();
        GR();
        GU();
        GRb();
        GUb();
        GR();
        GU();
        GRb();
        GUb();
    }
}

void Cube::turn_orange_angle(char first_colour, char second_colour, char third_colour) {
    if ((first_colour == 'w') && (second_colour == 'b') && (third_colour == 'o')) {
        steps += "OU OR OUb ORb ";
        OU();
        OR();
        OUb();
        ORb();
    }
    if ((first_colour == 'o') && (second_colour == 'w') && (third_colour == 'b')) {
        steps += "OR OU ORb OUb ";
        OR();
        OU();
        ORb();
        OUb();
    }
    if ((first_colour == 'b') && (second_colour == 'o') && (third_colour == 'w')) {
        steps += "OR OU ORb OUb OR OU ORb OUb OR OU ORb OUb ";
        OR();
        OU();
        ORb();
        OUb();
        OR();
        OU();
        ORb();
        OUb();
        OR();
        OU();
        ORb();
        OUb();
    }
}

void Cube::turn_blue_angle(char first_colour, char second_colour, char third_colour) {
    if ((first_colour == 'w') && (second_colour == 'r') && (third_colour == 'b')) {
        steps += "BU BR BUb BRb ";
        BU();
        BR();
        BUb();
        BRb();
    }
    else if ((first_colour == 'b') && (second_colour == 'w') && (third_colour == 'r')) {
        steps += "BR BU BRb BUb ";
        BR();
        BU();
        BRb();
        BUb();
    }
    else if ((first_colour == 'r') && (second_colour == 'b') && (third_colour == 'w')) {
        steps += "BR BU BRb BUb BR BU BRb BUb BR BU BRb BUb ";
        BR();
        BU();
        BRb();
        BUb();
        BR();
        BU();
        BRb();
        BUb();
        BR();
        BU();
        BRb();
        BUb();
    }
}

void Cube::turn_red_edge(char first_colour, char second_colour) {
    if (first_colour == 'r' && second_colour == 'b') {
        steps += "RUb RLb RUb RL RU RF RU RFb ";
        RUb();
        RLb();
        RUb();
        RL();
        RU();
        RF();
        RU();
        RFb();
    }
    if (first_colour == 'r' && second_colour == 'g') {
        steps += "RU RR RU RRb RUb RFb RUb RF ";
        RU();
        RR();
        RU();
        RRb();
        RUb();
        RFb();
        RUb();
        RF();
    }
}

void Cube::turn_green_edge(char first_colour, char second_colour) {
    if (first_colour == 'g' && second_colour == 'r') {
        steps += "GUb GLb GUb GL GU GF GU GFb ";
        GUb();
        GLb();
        GUb();
        GL();
        GU();
        GF();
        GU();
        GFb();
    }
    if (first_colour == 'g' && second_colour == 'o') {
        steps += "GU GR GU GRb GUb GFb GUb GF ";
        GU();
        GR();
        GU();
        GRb();
        GUb();
        GFb();
        GUb();
        GF();
    }
}

void Cube::turn_orange_edge(char first_colour, char c2) {
    if (first_colour == 'o' && c2 == 'g') {
        steps += "OUb OLb OUb OL OU OF OU OFb ";
        OUb();
        OLb();
        OUb();
        OL();
        OU();
        OF();
        OU();
        OFb();
    }
    if (first_colour == 'o' && c2 == 'b') {
        steps += "OU OR OU ORb OUb OFb OUb OF ";
        OU();
        OR();
        OU();
        ORb();
        OUb();
        OFb();
        OUb();
        OF();
    }
}

void Cube::turn_blue_edge(char first_colour, char c2) {
    if (first_colour == 'b' && c2 == 'o') {
        steps += "BUb BLb BUb BL BU BF BU BFb ";
        BUb();
        BLb();
        BUb();
        BL();
        BU();
        BF();
        BU();
        BFb();
    }
    if (first_colour == 'b' && c2 == 'r') {
        steps += "BU BR BU BRb BUb BFb BUb BF ";
        BU();
        BR();
        BU();
        BRb();
        BUb();
        BFb();
        BUb();
        BF();
    }
}

void Cube::turn_yellow(int x) {
    if (x == 1) {
        steps += "GF GU GR GFb GUb GRb ";
        GF();
        GU();
        GR();
        GUb();
        GRb();
        GFb();
    }
    else if (x == 2) {
        steps += "GF GR GU GRb GUb GFb ";
        GF();
        GR();
        GU();
        GRb();
        GUb();
        GFb();
    }
}

void Cube::turn_yellow_edgeR(char x) {
    if (x == 'l') {
        steps += "RU RBb RUb RUb RB RU RBb RU RB ";
        RU();
        RBb();
        RUb();
        RUb();
        RB();
        RU();
        RBb();
        RU();
        RB();
    }
    else if (x == 'r') {
        steps += "RU RLb RUb RUb RL RU RLb RU RL ";
        RU();
        RLb();
        RUb();
        RUb();
        RL();
        RU();
        RLb();
        RU();
        RL();
    }
    else if (x == 'c') {
        steps += "RU RRb RUb RUb RR RU RRb RU RR RU RBb RUb RUb RB RU RBb RU RB RU RRb RUb RUb RR RU RRb RU RR ";
        RU();
        RRb();
        RUb();
        RUb();
        RR();
        RU();
        RRb();
        RU();
        RR();
        RU();

        RBb();
        RUb();
        RUb();
        RB();
        RU();
        RBb();
        RU();
        RB();


        RU();
        RRb();
        RUb();
        RUb();
        RR();
        RU();
        RRb();
        RU();
        RR();
    }
}

void Cube::turn_yellow_edgeO(char x) {
    if (x == 'l') {
        steps += "OU OBb OUb OUb OB OU OBb OU OB ";
        OU();
        OBb();
        OUb();
        OUb();
        OB();
        OU();
        OBb();
        OU();
        OB();
    }
    else if (x == 'r') {
        steps += "OU OLb OUb OUb OL OU OLb OU OL ";
        OU();
        OLb();
        OUb();
        OUb();
        OL();
        OU();
        OLb();
        OU();
        OL();
    }
    else if (x == 'c') {
        steps += "OU ORb OUb OUb OR OU ORb OU OR OU OBb OUb OUb OB OU OBb OU OB OU ORb OUb OUb OR OU ORb OU OR ";
        OU();
        ORb();
        OUb();
        OUb();
        OR();
        OU();
        ORb();
        OU();
        OR();
        OU();

        OBb();
        OUb();
        OUb();
        OB();
        OU();
        OBb();
        OU();
        OB();

        OU();
        ORb();
        OUb();
        OUb();
        OR();
        OU();
        ORb();
        OU();
        OR();
    }
}

void Cube::turn_yellow_edgeB(char x) {
    if (x == 'l') {
        steps += "BU BBb BUb BUb BB BU BBb BU BB ";
        BU();
        BBb();
        BUb();
        BUb();
        BB();
        BU();
        BBb();
        BU();
        BB();
    }
    else if (x == 'r') {
        steps += "BU BLb BUb BUb BL BU BLb BU BL ";
        BU();
        BLb();
        BUb();
        BUb();
        BL();
        BU();
        BLb();
        BU();
        BL();
    }
    else if (x == 'c') {
        steps += "BU BRb BUb BUb BR BU BRb BU BR BU BBb BUb BUb BB BU BBb BU BB BU BRb BUb BUb BR BU BRb BU BR ";
        BU();
        BRb();
        BUb();
        BUb();
        BR();
        BU();
        BRb();
        BU();
        BR();
        BU();

        BBb();
        BUb();
        BUb();
        BB();
        BU();
        BBb();
        BU();
        BB();

        BU();
        BRb();
        BUb();
        BUb();
        BR();
        BU();
        BRb();
        BU();
        BR();
    }
}

void Cube::turn_yellow_edgeG(char x) {
    if (x == 'l') {
        steps += "GU GBb GUb GUb GB GU GBb GU GB ";
        GU();
        GBb();
        GUb();
        GUb();
        GB();
        GU();
        GBb();
        GU();
        GB();
    }
    else if (x == 'r') {
        steps += "GU GLb GUb GUb GL GU GLb GU GL ";
        GU();
        GLb();
        GUb();
        GUb();
        GL();
        GU();
        GLb();
        GU();
        GL();
    }
    else if (x == 'c') {
        steps += "GU GRb GUb GUb GR GU GRb GU GR GU GBb GUb GUb GB GU GBb GU GB GU GRb GUb GUb GR GU GRb GU GR ";
        GU();
        GRb();
        GUb();
        GUb();
        GR();
        GU();
        GRb();
        GU();
        GR();
        GU();

        GBb();
        GUb();
        GUb();
        GB();
        GU();
        GBb();
        GU();
        GB();

        GU();
        GRb();
        GUb();
        GUb();
        GR();
        GU();
        GRb();
        GU();
        GR();
    }
}

void Cube::solve() {
    turns_counter = 0;
    steps = "";
    solve_white_cross();
    solve_white_angle();
    solve_f2l();
    solve_yellow_cross();
    solve_right_yellow_cross();
    solve_right_yellow_angle();
    show();
    std::cout << ((checker.is_assembled(cube)) ? "Cube is solved" : "Cube isn't solved") << std::endl;
    std::cout << "Steps: " << steps << std::endl;
    std::cout << "Steps count: " << turns_counter << std::endl;
}
