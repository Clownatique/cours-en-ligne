
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>

#include "draw.h" // pour dessiner du point de vue d'une camera
#include "Viewer.h"

using namespace std;

Viewer::Viewer() : App(1024, 768),
                   mb_cullface(true),
                   mb_wireframe(false),
                   b_draw_grid(true),
                   b_draw_axe(true),
                   b_draw_animation(false),
                   b_debug_normals(false)
{
}

/*
 * Pour affichage du menu d aide.
 */
void Viewer::help()
{
    printf("HELP:\n");
    printf("\th: help\n");
    printf("\tc: (des)active GL_CULL_FACE\n");
    printf("\tw: (des)active wireframe\n");
    printf("\ta: (des)active l'affichage de l'axe\n");
    printf("\tg: (des)active l'affichage de la grille\n");
    printf("\tz: (des)active l'affichage de la courbe d'animation\n");
    printf("\tn: (des)active l'affichage des normales pour debug ; p/m pour agrandir/diminuer la norme du vecteur (en vert, normales par sommet fournies par l'application / en orange, normales geometriques des triangles -- les 2 doivent avoir le meme sens) \n");
    printf("\tfleches/pageUp/pageDown: bouge la camera\n");
    printf("\tCtrl+fleche/pageUp/pageDown: bouge la source de lumiere\n");
    printf("\tSouris+bouton gauche: rotation\n");
    printf("\tSouris mouvement vertical+bouton droit: (de)zoom\n");
}

/*
 * Creation du Mesh pour les axes.
 */
void Viewer::init_axe()
{
    m_axe = Mesh(GL_LINES);
    m_axe.color(Color(1, 0, 0));
    m_axe.vertex(0, 0, 0);
    m_axe.vertex(1, 0, 0);

    m_axe.color(Color(0, 1, 0));
    m_axe.vertex(0, 0, 0);
    m_axe.vertex(0, 1, 0);

    m_axe.color(Color(0, 0, 1));
    m_axe.vertex(0, 0, 0);
    m_axe.vertex(0, 0, 1);
}

/*
 * Creation du Mesh pour la grille.
 */
void Viewer::init_grid()
{
    m_grid = Mesh(GL_LINES);

    // m_grid.color(Color(1, 1, 1));
    m_grid.color(Color(0, 0, 0));

    for (int i = -5; i <= 5; ++i)
        for (int j = -5; j <= 5; ++j)
        {
            m_grid.vertex(-5, 0, j);
            m_grid.vertex(5, 0, j);

            m_grid.vertex(i, 0, -5);
            m_grid.vertex(i, 0, 5);
        }
}

/*
 * Creation du Mesh d un cube centre en (0, 0, 0) et de cote de taille 2.
 * Version cube indexe
 */
void Viewer::init_cube()
{
    std::cout << "init_cube" << std::endl;

    //       4---5
    //      /|  /|
    //     7---6 |
    //     | 0-|-1
    //     |/  |/
    //     3---2

    // Sommets                     0           1           2       3           4           5       6           7
    static float pt[8][3] = {{-1, -1, -1}, {1, -1, -1}, {1, -1, 1}, {-1, -1, 1}, {-1, 1, -1}, {1, 1, -1}, {1, 1, 1}, {-1, 1, 1}};

    // Faces                    0         1           2           3          4         5
    static int f[6][4] = {{0, 1, 2, 3}, {5, 4, 7, 6}, {2, 1, 5, 6}, {0, 3, 7, 4}, {3, 2, 6, 7}, {1, 0, 4, 5}};

    // Normales
    static float n[6][3] = {{0, -1, 0}, {0, 1, 0}, {1, 0, 0}, {-1, 0, 0}, {0, 0, 1}, {0, 0, -1}};

    m_cube = Mesh(GL_TRIANGLE_STRIP);
    m_cube.color(Color(1, 1, 1));

    // Parcours des 6 faces
    for (int i = 0; i < 6; i++)
    {
        m_cube.normal(n[i][0], n[i][1], n[i][2]);

        m_cube.texcoord(0, 0);
        m_cube.vertex(pt[f[i][0]][0], pt[f[i][0]][1], pt[f[i][0]][2]);

        m_cube.texcoord(1, 0);
        m_cube.vertex(pt[f[i][1]][0], pt[f[i][1]][1], pt[f[i][1]][2]);

        m_cube.texcoord(0, 1);
        m_cube.vertex(pt[f[i][3]][0], pt[f[i][3]][1], pt[f[i][3]][2]);

        m_cube.texcoord(1, 1);
        m_cube.vertex(pt[f[i][2]][0], pt[f[i][2]][1], pt[f[i][2]][2]);

        m_cube.restart_strip();
    }
}

/*
 * Creation du Mesh d un quad.
 */
void Viewer::init_quad()
{
    // On onsidere 4 sommets
    // v1   v3
    // v2   v4

    m_quad = Mesh(GL_TRIANGLES);
    m_quad.color(Color(1, 1, 1));

    // Normale du quad
    m_quad.normal(0, 0, 1);

    m_quad.texcoord(0, 1);
    int v1 = m_quad.vertex(-1, 1, 0);

    m_quad.texcoord(0, 0);
    int v2 = m_quad.vertex(-1, -1, 0);

    m_quad.texcoord(1, 1);
    int v3 = m_quad.vertex(1, 1, 0);

    m_quad.texcoord(1, 0);
    int v4 = m_quad.vertex(1, -1, 0);

    // 2 triangles = v1 v2 v3  et  v3 v2 v4
    m_quad.triangle(v1, v2, v3);
    m_quad.triangle(v3, v2, v4);
}

/*
 * Fonction dans laquelle les initialisations sont faites :
 * appel des fonctions init_votreObjet, chargement des textures.
 */
int Viewer::init()
{
    cout << " ==> l2_lifgraphique/Viewer " << endl;

    /// Appels de fonctions OpenGL pour l affichage
    //  glClearColor(0.5f, 0.5f, 0.9f, 1); // fond violet de la fenetre
    glClearColor(1.f, 1.f, 1.f, 1); // fond blanc de la fenetre

    glClearDepth(1.f);       // profondeur par defaut
    glDepthFunc(GL_LESS);    // ztest, conserver l'intersection la plus proche de la camera
    glEnable(GL_DEPTH_TEST); // active test profondeur
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);

    if (mb_cullface)
        glEnable(GL_CULL_FACE);
    else
        glDisable(GL_CULL_FACE); // good for debug

    // glEnable (GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // glAlphaFunc(GL_GREATER, 0.5);
    // glEnable(GL_ALPHA_TEST);

    /// Creation des donnees de la courbe de Bezier pour l animation
    m_anim.init(smart_path("data/animation/anim1.ani"));

    /// Camera
    m_camera.lookat(Point(0, 0, 0), 30);

    /// Lumiere : position et couleur
    // gl.light( Point(-2, 2, 2), White() );
    gl.light(Point(0, 20, 20), White());

    /// Appel des fonctions init_votreObjet pour creer les Mesh
    init_axe();
    init_grid();
    init_cube();
    init_quad();

    ///  Chargement des differentes textures des formes de base
    m_cube_texture = read_texture(0, smart_path("data/debug2x2red.png"));
    m_quad_texture = read_texture(0, smart_path("data/papillon.png"));

    return 0;
}

/*
 * Fonction pour l affichage des axes.
 */
void Viewer::draw_axe(const Transform &T)
{
    gl.model(T);
    gl.texture(0);
    gl.lighting(false);
    gl.draw(m_axe);
    gl.lighting(true);
}

/*
 * Fonction pour l affichage dun cube.
 */
void Viewer::draw_cube(const Transform &T, unsigned int tex)
{
    gl.model(T);
    gl.texture(tex);
    gl.draw(m_cube);

    // ou directement :
    // draw(m_cube, T, m_camera, tex);
}

/*
 * Fonction dans laquelle les appels pour les affichages sont effectues.
 */
int Viewer::render()
{
    // Efface l'ecran
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Deplace la camera, lumiere, etc.
    manageCameraLight();

    // donne notre camera au shader
    gl.camera(m_camera);

    /// Affichage d un quad avec texture de papillon

    // ou directement :
    // draw(m_quad, Tquad, m_camera, m_quad_texture);

    return 1;
}

/*
 * Fonction dans laquelle les mises a jours sont effectuees.
 */
int Viewer::update(const float time, const float delta)
{
    Tquad = Translation(3, 5, 0) * Rotation(Vector(0, 0, 1), 0.1f * time);

    return 1;
}

/*
 * Gestion de la camera et de la lumiere.
 */
void Viewer::manageCameraLight()
{
    // recupere les mouvements de la souris pour deplacer la camera, cf tutos/tuto6.cpp
    int mx, my;
    unsigned int mb = SDL_GetRelativeMouseState(&mx, &my);

    // deplace la camera
    if ((mb & SDL_BUTTON(1)) && (mb & SDL_BUTTON(3)))                                                // le bouton du milieu est enfonce
        m_camera.translation((float)mx / (float)window_width(), (float)my / (float)window_height()); // deplace le point de rotation
    else if (mb & SDL_BUTTON(1))                                                                     // le bouton gauche est enfonce
        m_camera.rotation(mx, my);                                                                   // tourne autour de l'objet
    else if (mb & SDL_BUTTON(3))                                                                     // le bouton droit est enfonce
        m_camera.move(my);                                                                           // approche / eloigne l'objet

    if (key_state(SDLK_PAGEUP) && (!key_state(SDLK_LCTRL)) && (!key_state(SDLK_LALT)))
    {
        m_camera.translation(0, 0.01);
    }

    if (key_state(SDLK_PAGEDOWN) && (!key_state(SDLK_LCTRL)) && (!key_state(SDLK_LALT)))
    {
        m_camera.translation(0, -0.01);
    }

    if (key_state(SDLK_LEFT) && (!key_state(SDLK_LCTRL)) && (!key_state(SDLK_LALT)))
    {
        m_camera.translation(0.01, 0);
    }

    if (key_state(SDLK_RIGHT) && (!key_state(SDLK_LCTRL)) && (!key_state(SDLK_LALT)))
    {
        m_camera.translation(-0.01, 0);
    }

    if (key_state(SDLK_UP) && (!key_state(SDLK_LCTRL)) && (!key_state(SDLK_LALT)))
    {
        m_camera.move(1);
    }

    if (key_state(SDLK_DOWN) && (!key_state(SDLK_LCTRL)) && (!key_state(SDLK_LALT)))
    {
        m_camera.move(-1);
    }

    // Deplace la lumiere
    const float step = 0.1f;
    if (key_state(SDLK_RIGHT) && key_state(SDLK_LCTRL))
    {
        gl.light(gl.light() + Vector(step, 0, 0));
    }
    if (key_state(SDLK_LEFT) && key_state(SDLK_LCTRL))
    {
        gl.light(gl.light() + Vector(-step, 0, 0));
    }
    if (key_state(SDLK_UP) && key_state(SDLK_LCTRL))
    {
        gl.light(gl.light() + Vector(0, 0, -step));
    }
    if (key_state(SDLK_DOWN) && key_state(SDLK_LCTRL))
    {
        gl.light(gl.light() + Vector(0, 0, step));
    }
    if (key_state(SDLK_PAGEUP) && key_state(SDLK_LCTRL))
    {
        gl.light(gl.light() + Vector(0, step, 0));
    }
    if (key_state(SDLK_PAGEDOWN) && key_state(SDLK_LCTRL))
    {
        gl.light(gl.light() + Vector(0, -step, 0));
    }

    // Affichage du menu help
    if (key_state('h'))
        help();

    // Affichage des faces cachees
    if (key_state('c'))
    {
        clear_key_state('c');
        mb_cullface = !mb_cullface;
        if (mb_cullface)
            glEnable(GL_CULL_FACE);
        else
            glDisable(GL_CULL_FACE);
    }

    // Affichage en fil de fer
    if (key_state('w'))
    {
        clear_key_state('w');
        mb_wireframe = !mb_wireframe;
        if (mb_wireframe)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    // (De)Active la grille / les axes
    if (key_state('g'))
    {
        b_draw_grid = !b_draw_grid;
        clear_key_state('g');
    }

    // (De)Active  les axes
    if (key_state('a'))
    {
        b_draw_axe = !b_draw_axe;
        clear_key_state('a');
    }

    // Pour afficher les normales des maillages (au depart à faux)
    if (key_state('n'))
    {
        b_debug_normals = !b_debug_normals;
        gl.debug_normals(b_debug_normals);
        clear_key_state('n');
    }

    // affiche la trajectoire pour l animation
    if (key_state('z'))
    {
        b_draw_animation = !b_draw_animation;
        if (b_draw_animation)
            m_anim.draw(m_camera);
        clear_key_state('z');
    }

    // mise en place de la camera
    gl.camera(m_camera);

    // AXE et GRILLE
    gl.model(Identity());

    // affichage de la grille
    if (b_draw_grid)
        gl.draw(m_grid);

    // affichage des axes
    if (b_draw_axe)
    {
        // Modification epaisseur pour voir les axes
        glLineWidth(9.f);
        gl.draw(m_axe);

        // On la remet à 1
        glLineWidth(1.f);
    }

    // LIGHT
    // Affichage d un cube pour representer la lumiere
    gl.texture(0);
    gl.lighting(false);
    gl.model(Translation(Vector(gl.light())) * Scale(0.3, 0.3, 0.3));
    gl.draw(m_cube);
    gl.lighting(true);

    // ou affichage ainsi de la lumiere
    // draw(m_cube, Translation(Vector(gl.light())) * Scale(0.3, 0.3, 0.3), m_camera);
}

int Viewer::quit()
{
    return 0;
}
