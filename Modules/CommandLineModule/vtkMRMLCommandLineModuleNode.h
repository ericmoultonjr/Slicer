/*=auto=========================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See Doc/copyright/copyright.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer
  Module:    $RCSfile: vtkMRMLCommandLineModuleNode.h,v $
  Date:      $Date: 2006/03/19 17:12:29 $
  Version:   $Revision: 1.3 $

=========================================================================auto=*/
#ifndef __vtkMRMLCommandLineModuleNode_h
#define __vtkMRMLCommandLineModuleNode_h

#include "vtkMRML.h"
#include "vtkMRMLNode.h"
#include "vtkMRMLStorageNode.h"

#include "vtkMatrix4x4.h"
#include "vtkTransform.h"

#include "vtkCommandLineModule.h"


class VTK_COMMANDLINEMODULE_EXPORT vtkMRMLCommandLineModuleNode : public vtkMRMLNode
{
  public:
  static vtkMRMLCommandLineModuleNode *New();
  vtkTypeMacro(vtkMRMLCommandLineModuleNode,vtkMRMLNode);
  void PrintSelf(ostream& os, vtkIndent indent);

  virtual vtkMRMLNode* CreateNodeInstance();

  // Description:
  // Set node attributes
  virtual void ReadXMLAttributes( const char** atts);

  // Description:
  // Write this node's information to a MRML file in XML format.
  virtual void WriteXML(ostream& of, int indent);

  // Description:
  // Copy the node's attributes to this object
  virtual void Copy(vtkMRMLNode *node);

  // Description:
  // Get node XML tag name (like Volume, Model)
  virtual const char* GetNodeTagName() {return "CommandLineModule";};

  // Description:
  // Get/Set Number of iterations (module parameter)
  vtkGetMacro(NumberOfIterations, int);
  vtkSetMacro(NumberOfIterations, int);

  // Description:
  // Get/Set Conductance (module parameter)
  vtkGetMacro(Conductance, double);
  vtkSetMacro(Conductance, double);

  // Description:
  // Get/Set time step (module parameter)
  vtkGetMacro(TimeStep, double);
  vtkSetMacro(TimeStep, double);
 
  // Description:
  // Get/Set input volume MRML Id
  vtkGetStringMacro(InputVolumeRef);
  vtkSetStringMacro(InputVolumeRef);
  
  // Description:
  // Get/Set output volume MRML Id
  vtkGetStringMacro(OutputVolumeRef);
  vtkSetStringMacro(OutputVolumeRef);

 
private:
  vtkMRMLCommandLineModuleNode();
  ~vtkMRMLCommandLineModuleNode();
  vtkMRMLCommandLineModuleNode(const vtkMRMLCommandLineModuleNode&);
  void operator=(const vtkMRMLCommandLineModuleNode&);

  double Conductance;
  double TimeStep;
  int NumberOfIterations;
  
  char* InputVolumeRef;
  char* OutputVolumeRef;

};

#endif

