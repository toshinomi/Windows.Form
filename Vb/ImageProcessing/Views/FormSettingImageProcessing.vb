''' <summary>
''' FormSettingImageProcessing のロジック
''' </summary>
Public Class FormSettingImageProcessing
    ''' <summary>
    ''' 画像処理タイプのコンボボックス
    ''' </summary>
    Public ReadOnly Property ComboBoxImageProcessingType() As System.Windows.Forms.ComboBox
        Get
            Return cmbBoxImageProcessingType
        End Get
    End Property

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()

        ' この呼び出しはデザイナーで必要です。
        InitializeComponent()

        ' InitializeComponent() 呼び出しの後で初期化を追加します。

        LoadParam()
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
        MyBase.Finalize()
    End Sub

    ''' <summary>
    ''' 設定の読込
    ''' </summary>
    Public Sub LoadParam()
        Dim items = New List(Of ComImageProcessingType)
        items.Add(New ComImageProcessingType(My.Settings.ImageTypeEdgeId, My.Settings.ImageTypeEdgeName))
        items.Add(New ComImageProcessingType(My.Settings.ImageTypeGrayScaleId, My.Settings.ImageTypeGrayScaleName))
        items.Add(New ComImageProcessingType(My.Settings.ImageTypeBinarizationId, My.Settings.ImageTypeBinarizationName))
        items.Add(New ComImageProcessingType(My.Settings.ImageTypeGrayScale2DiffId, My.Settings.ImageTypeGrayScale2DiffName))
        items.Add(New ComImageProcessingType(My.Settings.ImageTypeColorReversalId, My.Settings.ImageTypeColorReversalName))

        cmbBoxImageProcessingType.Items.Add(My.Settings.ImageTypeEdgeName)
        cmbBoxImageProcessingType.Items.Add(My.Settings.ImageTypeGrayScaleName)
        cmbBoxImageProcessingType.Items.Add(My.Settings.ImageTypeBinarizationName)
        cmbBoxImageProcessingType.Items.Add(My.Settings.ImageTypeGrayScale2DiffName)
        cmbBoxImageProcessingType.Items.Add(My.Settings.ImageTypeColorReversalName)
        cmbBoxImageProcessingType.SelectedIndex = items.Find(Function(x) x.Name = My.Settings.ImgTypeSelectName)?.Id - 1

        Return
    End Sub

    ''' <summary>
    ''' 設定の保存
    ''' </summary>
    Public Sub SaveParam()
        My.Settings.ImgTypeSelectName = cmbBoxImageProcessingType.SelectedItem.ToString()
        My.Settings.Save()

        Return
    End Sub

    ''' <summary>
    ''' OKボタンのクリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnClickOk(sender As Object, e As EventArgs) Handles btnOk.Click
        SaveParam()
        Me.DialogResult = DialogResult.OK
        Close()
    End Sub

    ''' <summary>
    ''' Cancelボタンのクリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnClickCancel(sender As Object, e As EventArgs) Handles btnCancel.Click
        Me.DialogResult = DialogResult.Cancel
        Close()
    End Sub
End Class