#pragma once

#include "musica.h"

class Siku : public LineaMusical
{
public:
    Siku(vector<Evento *> eventos) : LineaMusical(eventos)
    {
        m_envolvente.tiempoAtaque = 0.1;
        m_envolvente.tiempoDecaer = 0.1;
        m_envolvente.tiempoSoltar = 0.2;
        m_envolvente.nivelSostener = 0.5;
        
        m_armonicos = {1.0 / 2, 1.0 / 4, 1.0 / 4};
        m_onda = Onda::CUADRADA;
    }
};

class Harmonica : public LineaMusical{
public:
    Harmonica(vector<Evento *> eventos) : LineaMusical(eventos)
    {
        m_envolvente.tiempoAtaque = 0.07;
        m_envolvente.tiempoDecaer = 0.15;
        m_envolvente.tiempoSoltar = 0.1;
        m_envolvente.nivelSostener = 0.9;

        m_armonicos = {};
        double amplitud = 0.49;
        int i;
        for (i = 0; i <= 10; i+=2){
            m_armonicos.push_back(amplitud);
            m_armonicos.push_back(0);
            amplitud /= 2;
        }
        m_armonicos[i] *= 2;

        m_onda = Onda::SERRUCHO;
    }
};

class Sinte : public LineaMusical
{
public:
    Sinte(vector<Evento *> eventos) : LineaMusical(eventos)
    {
        m_envolvente.tiempoAtaque = 0.1;
        m_envolvente.tiempoDecaer = 0.1;
        m_envolvente.tiempoSoltar = 0.2;
        m_envolvente.nivelSostener = 0.7;

        m_armonicos = {};
        double amplitud = 0.5;
        for (int i = 1; i <= 8; i+=2){
            m_armonicos.push_back(amplitud);
            m_armonicos.push_back(0);
            amplitud /= 2;
        }
        m_onda = Onda::SENO;
    }
};