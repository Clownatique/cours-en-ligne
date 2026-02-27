
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include "draw.h"        // pour dessiner du point de vue d'une camera
#include "Viewer_etudiant.h"
#include "Viewer.h"

using namespace std;
/* Exemple de definition de fonction permettant la creation du Mesh de votre Objet.*/
//void ViewerEtudiant::init_votreObjet()
//{
//}

void ViewerEtudiant::init_disque(){
   const int div = 25;
   float step = 2.0 * M_PI / (div);
   // Choix primitive OpenGL
   m_disque = Mesh( GL_TRIANGLE_FAN );
   m_disque.normal( Vector(0,1,0) ); // Normale à la surface
   m_disque.vertex( Point(0,0,0) );
   // Variation de l’angle de 0 à 2𝝿
   for (int i=0; i<=div; ++i)
   {
      float alpha = i * step;
      m_disque.normal( Vector(0,1,0) );
      m_disque.vertex( Point(sin(alpha),0,cos(alpha)) );
   }
 }

void ViewerEtudiant::init_cylindre()
{
// Pour la variation de l’angle de 0 à 2𝝿
   const int div = 25;
   float step = 2.0 * M_PI / (div);
   // Choix primitive OpenGL
   m_cylindre = Mesh(GL_TRIANGLES);

   for (int i=0; i<=div; ++i){
      // Variation de l’angle de 0 à 2𝝿
      float alpha = i * step;
      float alpha2 = (i+1) * step;
      m_cylindre.normal( Vector(cos(alpha), 0, sin(alpha)) );
      int v0 = m_cylindre.vertex( Point(cos(alpha), 1, sin(alpha)) );

      m_cylindre.normal( Vector(cos(alpha), 0, sin(alpha)) );
      int v1 = m_cylindre.vertex( Point(cos(alpha), -1, sin(alpha)) );

      m_cylindre.normal( Vector(cos(alpha2), 0, sin(alpha2)) );
      int v2 = m_cylindre.vertex( Point(cos(alpha2), 1, sin(alpha2)) );

      m_cylindre.normal( Vector(cos(alpha2), 0, sin(alpha2)) );
      int v3 = m_cylindre.vertex( Point(cos(alpha2), -1, sin(alpha2)) );
      
      // 2 triangles formés avec les 4 sommets créés
      m_cylindre.triangle(v0,v1,v2);
      m_cylindre.triangle(v2,v1,v3);
   }
}

 void ViewerEtudiant::init_cone()
{
// Pour la variation de l’angle de 0 à 2𝝿
   const int div = 25;
   float step = 2.0 * M_PI / (div);
   // Choix de la primitive OpenGL
   m_cone = Mesh(GL_TRIANGLE_STRIP);
 
   for (int i=0;i<=div;++i){
      float alpha = i * step; // Angle varie de 0 à 2𝝿
      m_cone.normal(Vector(cos(alpha)/sqrtf(2.f),1/sqrtf(2.f), sin(alpha)/sqrtf(2.f) ));

      m_cone.vertex( Point( cos(alpha),0, sin(alpha) )); // Points du cercle

      m_cone.normal(Vector(cos(alpha)/sqrtf(2.f), 1.f/sqrtf(2.f),sin(alpha)/sqrtf(2.f) ));

      m_cone.vertex( Point(0, 1, 0) );// Sommet du cône
  }
}

void ViewerEtudiant::init_sphere(){
   // Choix de la primitive OpenGL
   m_sphere = Mesh(GL_TRIANGLES);
   int delta_a = 10; // Pas de la variation des angles
   int delta_b = 10; // Pas de la variation des angles
   // Variation de l’angle alpha
   
   for(int alpha=-90; alpha+delta_a <=90; alpha+=delta_a){
      int alpha2 = alpha+delta_a; // angle 𝝰 suivant
      // Variation de l’angle beta


      for(int beta=0; beta+delta_b <=360; beta+=delta_b){
         int beta2 = beta + delta_b; // angle 𝝱 suivant

         float alpha_r = radians(alpha);
         float alpha2_r = radians(alpha2);
         float beta_r = radians(beta);
         float beta2_r = radians(beta2);
         float x0 = cos(alpha_r) * cos(beta_r);
         float y0 = sin(alpha_r);
         float z0 = cos(alpha_r) * sin(beta_r);
         float x1 = cos(alpha2_r) * cos(beta_r);
         float y1 = sin(alpha2_r);
         float z1 = cos(alpha2_r) * sin(beta_r);
         float x2 = cos(alpha_r) * cos(beta2_r);
         float y2 = sin(alpha_r);
         float z2 = cos(alpha_r) * sin(beta2_r);
         float x3 = cos(alpha2_r) * cos(beta2_r);
         float y3 = sin(alpha2_r);
         float z3 = cos(alpha2_r) * sin(beta2_r);
         m_sphere.normal( Vector( x0, y0, z0));
         int v0 = m_sphere.vertex( Point (x0, y0, z0));

         m_sphere.normal( Vector( x1, y1, z1));
         int v1 = m_sphere.vertex( Point (x1, y1, z1));

         m_sphere.normal( Vector( x2, y2, z2));
         int v2 = m_sphere.vertex( Point (x2, y2, z2));

         m_sphere.normal( Vector( x3, y3, z3));
         int v3 = m_sphere.vertex( Point (x3, y3, z3));

         // Création de 2 triangles à partir des 4 sommets
         m_sphere.triangle(v0, v1, v2);
         m_sphere.triangle(v2, v1, v3);
      } // boucle beta
   } // boucle alpha
}// void

int ViewerEtudiant::init()
{
    Viewer::init();
    m_camera.lookat( Point(0,0,0), 150 );
    Viewer::init_cube();
    init_sphere();
    init_disque();
    /// Appel des fonctions init_votreObjet pour creer les Mesh
    /// Chargement des textures
    return 0;
}

/*
 * Exemple de definition de fonction permettant l affichage
 * de 'votreObjet' subissant la Transform T
 */
//void ViewerEtudiant::draw_votreObjet(const Transform& T)
//{
// gl.texture( tex );
// gl.model( T );
// gl.draw( m_votreObjet );

// ou directement 
// draw(m_votreObjet, T, m_camera, tex);
//}



void ViewerEtudiant::draw_cylindre(const Transform& T)
{
   // Corps du cylindre
   // gl.model( T );
   // gl.draw( m_cylindre );

   // Disque du haut
   // Transform Tch = T * Translation( 0, 1, 0);
   // gl.model( Tch );
   // gl.draw( m_disque);

   // Disque du bas
   Transform Tcb = T * Translation( 0, -1, 0) * Rotation( Vector(1,0,0), 180);
   gl.model( Tcb );
   gl.draw( m_disque);
}
/* Fonction dans laquelle les appels pour les affichages sont effectues.*/
int ViewerEtudiant::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Transform T = Translation( 2, 1, 1 );
    // Transform R = Rotation( Vector(1, 0, 0), 90 );
    // Transform S = Scale(2, 1, 4);
    manageCameraLight();
    gl.camera(m_camera);

    Transform T_init = Identity();
    gl.model( T_init );
    gl.draw(m_disque);
    // Viewer::draw_cube(T, 1);
    // Viewer::draw_cube(S, 1);
    /// Appel de la fonction render() de la class Viewer
    /// pour que vous voyez apparaitre un premier objet : quad avec texture de papillon
    /// a supprimer ensuite
    // Viewer::render();
    /// Appel des fonctions du type 'draw_votreObjet'
    // draw_votreObjet(const Transform& T);
    return 1;
}

/* Fonction dans laquelle les mises a jours sont effectuees.*/
int ViewerEtudiant::update( const float time, const float delta )
{
    // time est le temps ecoule depuis le demarrage de l'application, en millisecondes,
    // delta est le temps ecoule depuis l'affichage de la derniere image / le dernier appel a draw(), en millisecondes.
    return 0;
}

/* Constructeur */

ViewerEtudiant::ViewerEtudiant() : Viewer(){}
/* Programme principal. */
int main( int argc, char **argv )
{
    ViewerEtudiant v;
    v.run();
    return 0;
}
