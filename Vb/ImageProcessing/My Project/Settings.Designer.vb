﻿'------------------------------------------------------------------------------
' <auto-generated>
'     このコードはツールによって生成されました。
'     ランタイム バージョン:4.0.30319.42000
'
'     このファイルへの変更は、以下の状況下で不正な動作の原因になったり、
'     コードが再生成されるときに損失したりします。
' </auto-generated>
'------------------------------------------------------------------------------

Option Strict On
Option Explicit On


Namespace My
    
    <Global.System.Runtime.CompilerServices.CompilerGeneratedAttribute(),  _
     Global.System.CodeDom.Compiler.GeneratedCodeAttribute("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "16.2.0.0"),  _
     Global.System.ComponentModel.EditorBrowsableAttribute(Global.System.ComponentModel.EditorBrowsableState.Advanced)>  _
    Partial Friend NotInheritable Class MySettings
        Inherits Global.System.Configuration.ApplicationSettingsBase
        
        Private Shared defaultInstance As MySettings = CType(Global.System.Configuration.ApplicationSettingsBase.Synchronized(New MySettings()),MySettings)
        
#Region "My.Settings 自動保存機能"
#If _MyType = "WindowsForms" Then
    Private Shared addedHandler As Boolean

    Private Shared addedHandlerLockObject As New Object

    <Global.System.Diagnostics.DebuggerNonUserCodeAttribute(), Global.System.ComponentModel.EditorBrowsableAttribute(Global.System.ComponentModel.EditorBrowsableState.Advanced)> _
    Private Shared Sub AutoSaveSettings(sender As Global.System.Object, e As Global.System.EventArgs)
        If My.Application.SaveMySettingsOnExit Then
            My.Settings.Save()
        End If
    End Sub
#End If
#End Region
        
        Public Shared ReadOnly Property [Default]() As MySettings
            Get
                
#If _MyType = "WindowsForms" Then
               If Not addedHandler Then
                    SyncLock addedHandlerLockObject
                        If Not addedHandler Then
                            AddHandler My.Application.Shutdown, AddressOf AutoSaveSettings
                            addedHandler = True
                        End If
                    End SyncLock
                End If
#End If
                Return defaultInstance
            End Get
        End Property
        
        <Global.System.Configuration.UserScopedSettingAttribute(),  _
         Global.System.Diagnostics.DebuggerNonUserCodeAttribute(),  _
         Global.System.Configuration.DefaultSettingValueAttribute("EdgeDetection")>  _
        Public Property ImgTypeSelectName() As String
            Get
                Return CType(Me("ImgTypeSelectName"),String)
            End Get
            Set
                Me("ImgTypeSelectName") = value
            End Set
        End Property
        
        <Global.System.Configuration.UserScopedSettingAttribute(),  _
         Global.System.Diagnostics.DebuggerNonUserCodeAttribute(),
         Global.System.Configuration.DefaultSettingValueAttribute("1")>
        Public Property ImageTypeEdgeId() As Integer
            Get
                Return CType(Me("ImageTypeEdgeId"), Integer)
            End Get
            Set
                Me("ImageTypeEdgeId") = Value
            End Set
        End Property

        <Global.System.Configuration.UserScopedSettingAttribute(),  _
         Global.System.Diagnostics.DebuggerNonUserCodeAttribute(),
         Global.System.Configuration.DefaultSettingValueAttribute("EdgeDetection")>
        Public Property ImageTypeEdgeName() As String
            Get
                Return CType(Me("ImageTypeEdgeName"), String)
            End Get
            Set
                Me("ImageTypeEdgeName") = Value
            End Set
        End Property

        <Global.System.Configuration.UserScopedSettingAttribute(),  _
         Global.System.Diagnostics.DebuggerNonUserCodeAttribute(),
         Global.System.Configuration.DefaultSettingValueAttribute("2")>
        Public Property ImageTypeGrayScaleId() As Integer
            Get
                Return CType(Me("ImageTypeGrayScaleId"), Integer)
            End Get
            Set
                Me("ImageTypeGrayScaleId") = Value
            End Set
        End Property

        <Global.System.Configuration.UserScopedSettingAttribute(),  _
         Global.System.Diagnostics.DebuggerNonUserCodeAttribute(),
         Global.System.Configuration.DefaultSettingValueAttribute("GrayScale")>
        Public Property ImageTypeGrayScaleName() As String
            Get
                Return CType(Me("ImageTypeGrayScaleName"), String)
            End Get
            Set
                Me("ImageTypeGrayScaleName") = Value
            End Set
        End Property

        <Global.System.Configuration.UserScopedSettingAttribute(),  _
         Global.System.Diagnostics.DebuggerNonUserCodeAttribute(),
         Global.System.Configuration.DefaultSettingValueAttribute("3")>
        Public Property ImageTypeBinarizationId() As Integer
            Get
                Return CType(Me("ImageTypeBinarizationId"), Integer)
            End Get
            Set
                Me("ImageTypeBinarizationId") = Value
            End Set
        End Property

        <Global.System.Configuration.UserScopedSettingAttribute(),  _
         Global.System.Diagnostics.DebuggerNonUserCodeAttribute(),
         Global.System.Configuration.DefaultSettingValueAttribute("Binarization")>
        Public Property ImageTypeBinarizationName() As String
            Get
                Return CType(Me("ImageTypeBinarizationName"), String)
            End Get
            Set
                Me("ImageTypeBinarizationName") = Value
            End Set
        End Property

        <Global.System.Configuration.UserScopedSettingAttribute(),  _
         Global.System.Diagnostics.DebuggerNonUserCodeAttribute(),
         Global.System.Configuration.DefaultSettingValueAttribute("4")>
        Public Property ImageTypeGrayScale2DiffId() As Integer
            Get
                Return CType(Me("ImageTypeGrayScale2DiffId"), Integer)
            End Get
            Set
                Me("ImageTypeGrayScale2DiffId") = Value
            End Set
        End Property

        <Global.System.Configuration.UserScopedSettingAttribute(),  _
         Global.System.Diagnostics.DebuggerNonUserCodeAttribute(),
         Global.System.Configuration.DefaultSettingValueAttribute("GrayScale 2Diff")>
        Public Property ImageTypeGrayScale2DiffName() As String
            Get
                Return CType(Me("ImageTypeGrayScale2DiffName"), String)
            End Get
            Set
                Me("ImageTypeGrayScale2DiffName") = Value
            End Set
        End Property

        <Global.System.Configuration.UserScopedSettingAttribute(),  _
         Global.System.Diagnostics.DebuggerNonUserCodeAttribute(),
         Global.System.Configuration.DefaultSettingValueAttribute("5")>
        Public Property ImageTypeColorReversalId() As Integer
            Get
                Return CType(Me("ImageTypeColorReversalId"), Integer)
            End Get
            Set
                Me("ImageTypeColorReversalId") = Value
            End Set
        End Property

        <Global.System.Configuration.UserScopedSettingAttribute(),  _
         Global.System.Diagnostics.DebuggerNonUserCodeAttribute(),
         Global.System.Configuration.DefaultSettingValueAttribute("ColorReversal")>
        Public Property ImageTypeColorReversalName() As String
            Get
                Return CType(Me("ImageTypeColorReversalName"), String)
            End Get
            Set
                Me("ImageTypeColorReversalName") = Value
            End Set
        End Property
    End Class
End Namespace

Namespace My
    
    <Global.Microsoft.VisualBasic.HideModuleNameAttribute(),  _
     Global.System.Diagnostics.DebuggerNonUserCodeAttribute(),  _
     Global.System.Runtime.CompilerServices.CompilerGeneratedAttribute()>  _
    Friend Module MySettingsProperty
        
        <Global.System.ComponentModel.Design.HelpKeywordAttribute("My.Settings")>  _
        Friend ReadOnly Property Settings() As Global.ImageProcessing.My.MySettings
            Get
                Return Global.ImageProcessing.My.MySettings.Default
            End Get
        End Property
    End Module
End Namespace
