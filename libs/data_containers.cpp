/*
QSTEM - image simulation for TEM/STEM/CBED
    Copyright (C) 2000-2010  Christoph Koch
	Copyright (C) 2010-2013  Christoph Koch, Michael Sarahan

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "stdio.h"
#include <string.h>
#include "data_containers.hpp"
#include "memory_fftw3.hpp"

Detector::Detector(int nx, int ny, float_tt resX, float_tt resY) :
  error(0),
  shiftX(0),
  shiftY(0),
  Navg(0),
  dx(resX),
  dy(resY)
{
  image = float2D(nx,ny,"ADFimag");
  image2 = float2D(nx,ny,"ADFimag");
  
  // TODO: need way of passing file formats into constructor here
  m_imageIO=ImageIOPtr(new CImageIO(nx, ny));
}

void Detector::WriteImage(const char *fileName, const char *comment, std::map<std::string, double> &params,
                          std::vector<unsigned> position)
{
  params["dx"]=dx;
  params["dy"]=dy;
  // Thickness is set externally and passed in on params
  m_imageIO->WriteRealImage((void **)image, fileName, params, std::string(comment), position);
}

MULS::MULS():
  cubex(0), cubey(0), cubez(0),
  printLevel(2),
  saveLevel(0),
  displayPotCalcInterval(1000),
  cellDiv(1),
  btiltx(0),btilty(0),tiltBack(true),
  ctiltx(0),ctilty(0),ctiltz(0),
  natom(0),
  atoms(NULL),
  Znums(NULL),
  atomKinds(0),
  u2(NULL),
  u2avg(NULL),
  xOffset(0), yOffset(0),
  resolutionX(0), resolutionY(0),
  centerSlices(false), sliceThickness(0),
  lpartl(0),
  atomRadius(5.0),
  saveFlag(0),
  sigmaf(0),
  dfdelt(0),
  acmax(0),
  acmin(0),
  aobj(0),
  Cs(0),
  aAIS(0),
  periodicZ(false),periodicXY(false),
  bandlimittrans(true),
  readPotential(false),
  savePotential(false),
  saveTotalPotential(false),
  plotPotential(false),
  fftpotential(true),
  potential3D(true),
  avgRuns(10),
  storeSeries(false),
  dE_E(0),dI_I(0),dV_V(0),
  sourceRadius(0),gaussScale(0.05),gaussFlag(false),
  potOffsetY(0),potOffsetX(0),
  tomoTilt(0),
  tomoStart(0),
  tomoStep(0),
  tomoCount(0),
  trans(NULL),
  cz(NULL),
  scatFactor(DOYLE_TURNER),
  normHolog(0),
  gaussianProp(0),
  kx(NULL), kx2(NULL), ky(NULL), ky2(NULL),
  pendelloesung(NULL),
  onlyFresnel(NULL),
  showPhaseplate(NULL),
  czOffset(NULL)
{

}
